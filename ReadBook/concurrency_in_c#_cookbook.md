# Concurrency in C# Cookbook
## 第一章并发编程概述


```csharp
using System;
using System.Diagnostics;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        public async Task DoSomethingAsync()
        {
            int val = 13;

            // 异步方式等待1秒
            await Task.Delay(TimeSpan.FromSeconds(1));

            val *= 2;

            // 异步方式等待
            await Task.Delay(TimeSpan.FromSeconds(1));
            Trace.WriteLine(val);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Program a = new Program();
            Task task = a.DoSomethingAsync();
        }
        
    }
}

```

- 使用task.delay()实现一个简单的超时功能
```csharp
static async Task<string> DownloadStringAndTimeout(string url)
{
    using (var client = new HttpClient()) {
        var downlaodTask = client.GetStringAsync(url);
        var timeoutTask = Task.Delay(3000);

        var completedTask = await Task.WhenAny(downlaodTask, timeoutTask);
        if (completedTask == timeoutTask)
        {
            return null;
        }
        return await downlaodTask;
    }
}
        
```
实现超时 `CancellationToken`  ,Task.Delay()实现调试、重复逻辑。

在异步方法中需要避免阻塞操作,避免造成死锁
```csharp
private static readonly Task<int> zeroTask = Task.FromResult(0);
static Task<int> getValueAsync()
{
    return zeroTask;
}
```
- 实现一个异步签名的同步方法

```csharp
interface IMyAsyncInterface
{
    Task<int> GetValueAsync();
}
class MySychronousImplementation : IMyAsyncInterface
{
    public Task<int> GetValueAsync()
    {
        return Task.FromResult(13);
    }
}
 
```
- 等待一组任务完成
```csharp
static async Task<string> DownloadAllAsync(IEnumerable<string> urls)
{
    var httpClient = new HttpClient();

    // 定义每一个url的使用方法
    var downloads = urls.Select(url => httpClient.GetStringAsync(url));

    // 所有的url下载同步开始
    Task<string>[] downloadTasks = downloads.ToArray();
    
    // 使用异步的方式等待下载完成

    string[] htmlPages = await Task.WhenAll(downloadTasks);

    return string.Concat(htmlPages);
}
```

- 任务完成时的处理  
```csharp
// 完成时的任务处理
static async Task<int> DelayAndReturnAsync(int val)
{
    await Task.Delay(TimeSpan.FromSeconds(val));
    return val;
}

static async Task AwaitAndProcessAsync(Task<int> task)
{
    var result = await task;
    Trace.WriteLine(result);
}

// 这个方法输出 1、2、3
static async Task ProcessTaskAsync()
{
    // 创建任务队列
    Task<int> task = DelayAndReturnAsync(2);
    Task<int> task1 = DelayAndReturnAsync(1);
    Task<int> task2 = DelayAndReturnAsync(3);

    var tasks = new[] { task, task1, task2 };

    var processingTask = (from t in tasks
                            select AwaitAndProcessAsync(t)).ToArray();

    //另一种写法
    //var processingTask = tasks.Select(async t =>
    //{
    //    var result = await t;
    //    Trace.WriteLine(result);
    //}).ToArray();

    // 等待全部任务处理完成
    await Task.WhenAll(processingTask);
}
```
`await Task.Delay(TimeSpan.FromSeconds(1)).ConfigureAwait(false);`  
在调用的线程里执行，如果await之后，在线程池里继续执行


## 参考
[Async/Await - Best Practices in Asynchronous Programming](https://msdn.microsoft.com/en-us/magazine/jj991977.aspx)  

[Asynchronous programming with async and await (C#)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/)  
