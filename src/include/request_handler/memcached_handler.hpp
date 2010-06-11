
#ifndef __MEMCACHED_HANDLER_HPP__
#define __MEMCACHED_HANDLER_HPP__

#include "request_handler/request_handler.hpp"
#include "config/code.hpp"

template<class config_t>
class memcached_handler_t : public request_handler_t<config_t> {
public:
    typedef typename config_t::alloc_t alloc_t;
    typedef typename config_t::cache_t cache_t;
    typedef typename config_t::conn_fsm_t conn_fsm_t;
    typedef typename config_t::request_t request_t;
    typedef typename config_t::btree_fsm_t btree_fsm_t;
    typedef typename config_t::btree_set_fsm_t btree_set_fsm_t;
    typedef typename config_t::btree_get_fsm_t btree_get_fsm_t;
    typedef typename config_t::req_handler_t req_handler_t;
    typedef typename req_handler_t::parse_result_t parse_result_t;
    
public:
    memcached_handler_t(cache_t *_cache, alloc_t *_alloc, event_queue_t *eq)
        : req_handler_t(eq), cache(_cache), alloc(_alloc)
        {}
    
    virtual parse_result_t parse_request(event_t *event);
    virtual void build_response(request_t *request);

private:
    cache_t *cache;
    alloc_t *alloc;
};

#include "request_handler/memcached_handler_impl.hpp"

#endif // __MEMCACHED_HANDLER_HPP__

