

2019年2月28日
* 修改宕机问题

* 内存泄漏修改  
    `releaseMessageManager::get_instance().release_all_msg();`
* 消息缓存修改  
    使用`google::protobuf::Any m_msg;`

* 交易收款bug修改
    ```c
    /* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
    __MATHCALLX (round,, (_Mdouble_ __x), (__const__));
    ```
    ```CPP
    static_cast<uint32_t>(round(static_cast<double>(total_price) * shopping_tax_per / 100));
    ```

使用auto 和 uint


