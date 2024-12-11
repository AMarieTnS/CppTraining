#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <string>

/**
 * @class Skeleton
 * @brief Class representing the server-side skeleton for processing requests.
 */
class Skeleton
{
public:
    /* Constructors */
    Skeleton() = default;
    Skeleton(const Skeleton &other) = delete;
    Skeleton(Skeleton &&other) = delete;
    Skeleton &operator=(const Skeleton &other) = delete;
    Skeleton &operator=(Skeleton &&other) = delete;
    ~Skeleton() = default;

    /* Execution Functions */
    /**
     * @brief Processes a request received from the client.
     * @param[in] request  The request to process.
     * @return The response after processing.
     */
    std::string ProcessRequest(const std::string &request);
};

#endif