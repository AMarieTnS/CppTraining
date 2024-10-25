#include "../Includes/Fixed.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

Fixed::Fixed() : iFixedPointValue(0) {}
Fixed::Fixed(const int iValue) { iFixedPointValue = iValue << iFractionalBits; }
Fixed::Fixed(const float fValue) {
  iFixedPointValue = roundf(fValue * (1 << iFractionalBits));
}
Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy) { *this = copy; }
Fixed &Fixed::operator=(const Fixed &Overload) {
  this->iFixedPointValue = Overload.getRawBits();
  return *this;
}
int Fixed::getRawBits(void) const { return this->iFixedPointValue; }
void Fixed::setRawBits(int const raw) { this->iFixedPointValue = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(iFixedPointValue) / (1 << iFractionalBits);
}
int Fixed::toInt(void) const { return iFixedPointValue >> iFractionalBits; }

std::ostream &operator<<(std::ostream &OutValue, const Fixed &sFixed) {
  OutValue << sFixed.toFloat();
  return OutValue;
}

bool Fixed::operator>(const Fixed &Value) const {
  return this->iFixedPointValue > Value.getRawBits();
}
bool Fixed::operator<(const Fixed &Value) const {
  return this->iFixedPointValue < Value.getRawBits();
}
bool Fixed::operator>=(const Fixed &Value) const {
  return this->iFixedPointValue >= Value.getRawBits();
}
bool Fixed::operator<=(const Fixed &Value) const {
  return this->iFixedPointValue <= Value.getRawBits();
}
bool Fixed::operator==(const Fixed &Value) const {
  return this->iFixedPointValue == Value.getRawBits();
}
bool Fixed::operator!=(const Fixed &Value) const {
  return this->iFixedPointValue != Value.getRawBits();
}

Fixed Fixed::operator+(const Fixed &Value) {
  return Fixed(toFloat() + Value.toFloat());
}
Fixed Fixed::operator-(const Fixed &Value) {
  return Fixed(toFloat() - Value.toFloat());
}
Fixed Fixed::operator*(const Fixed &Value) {
  return Fixed(toFloat() * Value.toFloat());
}
Fixed Fixed::operator/(const Fixed &Value) {
  return Fixed(toFloat() / Value.toFloat());
}

Fixed &Fixed::operator++() {
  iFixedPointValue++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  ++iFixedPointValue;
  return temp;
}

Fixed &Fixed::operator--() {
  iFixedPointValue--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  --iFixedPointValue;
  return temp;
}

Fixed &Fixed::min(Fixed &ValueA, Fixed &ValueB) {
  Fixed *MinValue = &ValueA;
  if (ValueA > ValueB) {
    MinValue = &ValueB;
  }
  return *MinValue;
}

Fixed &Fixed::max(Fixed &ValueA, Fixed &ValueB) {
  Fixed *MaxValue = &ValueA;
  if (ValueA < ValueB) {
    MaxValue = &ValueB;
  }
  return *MaxValue;
}

const Fixed &Fixed::min(const Fixed &ValueA, const Fixed &ValueB) {
  Fixed const *MinValue = &ValueA;
  if (ValueA > ValueB) {
    MinValue = &ValueB;
  }
  return *MinValue;
}

const Fixed &Fixed::max(const Fixed &ValueA, const Fixed &ValueB) {
  Fixed const *MaxValue = &ValueA;
  if (ValueA < ValueB) {
    MaxValue = &ValueB;
  }
  return *MaxValue;
}
Fixed applyOperator(Fixed valueA, Fixed valueB, char cOperateur) {
  switch (cOperateur) {
  case '+':
    return valueA + valueB;
  case '-':
    return valueA - valueB;
  case '*':
    return valueA * valueB;
  case '/':
    return valueA / valueB;
  default:
    throw std::invalid_argument("Opérateur non supporté");
  }
}

Fixed Fixed::Expression(const std::string &sRawExpression) {
  std::istringstream iss(sRawExpression);
  std::stack<Fixed> StackValues;
  std::stack<char> StackOperators;
  std::string sToken;
  char cOperateur;
  float fValue;

  while (iss >> sToken) {
    std::istringstream tokenStream(sToken);
    if (tokenStream >> fValue) {
      StackValues.push(Fixed(fValue));
    } else {
      tokenStream.clear();
      tokenStream.str(sToken);
      tokenStream >> cOperateur;
      if (cOperateur == '(') {
        StackOperators.push(cOperateur);
      } else if (cOperateur == ')') {
        while (!StackOperators.empty() && StackOperators.top() != '(') {
          Fixed valueB = StackValues.top();
          StackValues.pop();
          Fixed valueA = StackValues.top();
          StackValues.pop();
          char op = StackOperators.top();
          StackOperators.pop();
          Fixed result = applyOperator(valueA, valueB, op);
          StackValues.push(result);
        }
        StackOperators.pop();
      } else {
        while (!StackOperators.empty() &&
               (StackOperators.top() == '*' || StackOperators.top() == '/')) {
          Fixed valueB = StackValues.top();
          StackValues.pop();
          Fixed valueA = StackValues.top();
          StackValues.pop();
          char op = StackOperators.top();
          StackOperators.pop();
          Fixed result = applyOperator(valueA, valueB, op);
          StackValues.push(result);
        }
        StackOperators.push(cOperateur);
      }
    }
  }
  while (!StackOperators.empty()) {
    Fixed valueB = StackValues.top();
    StackValues.pop();
    Fixed valueA = StackValues.top();
    StackValues.pop();
    char op = StackOperators.top();
    StackOperators.pop();
    Fixed result = applyOperator(valueA, valueB, op);
    StackValues.push(result);
  }

  return StackValues.top();
}

/*
  Methode de trie
  séparer chaque element, savoir reconnaitre :
      - () -> gerer prioriter des expressions
      - + -> appel vers fonction
      - - -> appel vers fonction
      - * -> appel vers fonction
      - / -> appel vers fonction

  ordre :
    - prendre parenthese,
        si multiplication a cote, alors operation
        sinon operation dans parentheses

        operation, prioriser * > / > + > -
  */

/*
stack valeur
stack operation

on stock les valeurs et en fonction des operations, opère ou non
si


exemple :
expression = "18.18 + 3.03 * 2"
while (iss >> token) {
1) 18.18 -> push valeur
2) + -> push operation
3) 3.03 -> push valeur
4) * -> push operation
5) 2 -> push valeur
6) 3.03 * 2 ->
    - valueB = top valeur
    - pop value
    - op = top operation
    - pop operation
    - valueA = top valeur
    - pop value
    - result = valueA op valueB
    - push result
plus de valeurs a ajouter donc on prend les precedents
6.1) 18.18 + result ->
    - valueB = top valeur
    - pop value
    - op = top operation
    - pop operation
    - valueA = top valeur
    - pop value
    - result = valueA op valueB
*/