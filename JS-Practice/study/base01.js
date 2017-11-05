/**
 * XMLHttpRequest
 * ================
 * responseText
 * responseXML
 * status
 * statusText
 * readyState
 *    0: 未初始化. 没有调用open()
 *    1: 启动. 调用open(), 未调用send()
 *    2: 发送. 调用send(), 未收到响应
 *    3: 接收. 收到部分响应数据
 *    4: 完成. 收到全部响应数据.
 */
/**
 * HTTP 头部
 * ================
 * 发送XHR的同时
 * Accept: 浏览器能够处理的内容类型
 * Accept-Charset: 浏览器能够显示的字符集
 * Accept-Encoding: 浏览器能够处理的压缩编码
 * Connection: 浏览器与服务器之间连接的类型
 * Cookie: 当前页面设置的任何cookie
 * Host: 发出请求的页面所在的域
 * Referer: 发出请求的URI
 * User-Agent: 浏览器的用户代理字符串
 * 
 */

(function(){
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function () {
		if(xhr.readyState == 4){
			if(xhr.status >= 200 && xhr.status < 300 || xhr.status == 304){
				console.log(xhr.responseText);
			} else {
				console.log("unsuccess");
			}
		}
	};
	xhr.open('get', 'www.baidu.com', true);
	xhr.setRequestHeader("myHeader", "myValue");
	xhr.send(null);
	//xhr.getResponseHeader("myHeader");
	//xhr.getAllResponseHeaders();
})();

(function(){
	var xhr  =new XMLHttpRequest();
	xhr.onreadystatechange(function(){
		if(xhr.readyState == 4){
			if(xhr.status >= 200 && xhr.status < 300 || xhr.status == 304){
				console.log(xhr.responseText);
			} else {
				console.log("unsuccess");
			}
		}
	});
	xhr.open('post', 'www.baidu.com', false);
	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhr.send(serialize(form));
})();

/**
 * XMLHttpRequest2 级
 * ==================
 * FormData类型: 
 *     FormData(form)
 *     append(key, value): 添加键值对
 */

(function () {
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function (){
		if(xhr.readyState == 4){
			if(xhr.status >= 200 && xhr.status < 300 || xhr.status == 304){
				console.log(xhr.responseText);
			} else {
				console.log("unsuccess");
			}
		}
	};
	xhr.open('get', 'www.baidu.com', true);
	xhr.timeout = 1000;
	xhr.ontimeout = function (){
		console.log("timeout");
	};
	xhr.overrideMimeType('text/xml');
	var form = document.getElementById('formName');
	xhr.send(new FormDate(form));
})();

/**
 * 进度事件
 * =======
 * loadstart: 在接收响应数据的第一个字节时触发
 * progress: 在接收响应期间持续不断地触发
 *     onprogress事件可以接收event对象. 其target属性是XHR对象,包含三个属性
 *         1. lengthComputable: 进度信息是否可用的布尔值
 *         2. position: 表示已接受的字节数
 *         3. totalSize: 表示根据Content-Length响应头部确定的预期字节数
 * error: 在请求发生错误时触发
 * abort: 在因为调用abort()方法而终止连接时触发
 * load: 在接收到完整的响应数据时触发
 * loadend: 在通信完成或触发error, abort或load事件后触发
 */
(function () {
	var xhr = new XMLHttpRequest();
	xhr.onload = function (){
		if(xhr.status >= 200 && xhr.status < 300 || xhr.status == 304){
			console.log(xhr.responseText);
		} else {
			console.log("unsuccess");
		}
	};
	xhr.onprogress = function (event) {
		if(event.lengthComputable){
			console.log("Receive " + event.position + " of " + event.totalSize);
		}
	};
	xhr.open("get", "www.baidu.com", true);
	xhr.send(null);
})();

(function(){
	function upload (url, form, options) {
		var xhr = new XMLHttpRequest();
		xhr.onload = function (event) {
			if(xhr.status >= 200 && xhr.status < 300 || xhr.status == 304){
				options.onload();
			}
		};
		xhr.onerror = function (event) {
			options.onerror();
		};
		xhr.onprogress = function (event) {
			options.onprogress();
		};
		xhr.open("post", url, true);
		//var data = new FormData(form);
		var data = serialze(form);
		xhr.send(data);
	}
})();

/**
 * 跨域技术
 * =======
 *     1. 图像 Ping
 *     2. JSONP
 *     3. Comet
 *         1. 轮询
 *         2. 流
 */

(function(){
	function handleResponse(response){
		console.log("You're at IP: " + response.ip + ", City: " + response.city + ", " + response.region_name);
	}

	var script = document.createElement("script");
	script.src = "http://freegeoip.net/json?callback=handleResponse";
	document.body.insertBefore(script, document.body.firstChild);
})();

(function(){
	function createStreamingClient (url, progress, finish) {
		var xhr = new XMLHttpRequest();
		var received = 0;

		xhr.onreadystatechange = function () {
			var result;
			if(xhr.readyState == 3){
				result = xhr.responseText.substring(received);
				received += result.length();
				progress(result);
			} else if(xhr.readyState == 4){
				finish(xhr.responseText);
			}
		};
	}
})();

/**
 * SSE 服务器发送事件
 * ================
 * EventSource对象
 *    readyState
 *        0: 正在连接到服务器
 *        1: 打开了连接
 *        2: 关闭了连接
 *    事件
 *        open: 建立时触发
 *        message: 从服务器接收到新事件时触发
 *        error: 在无法建立连接时触发
 *    event.data: 以字符串形式保存服务器发回的数据
 *    close(): 断开连接
 */
(function () {
	var source = new EventSource();
	source.onmessage = function (event) {
		console.log(event.data);
	};
})();

/**
 * Web Socket
 * ==========
 * WebSocket对象
 *     readyState
 *         WebSocket.OPENING(0): 正在建立连接
 *         WebSocket.OPEN(1): 已经建立连接
 *         WebSocket.CLOSING(2): 正在关闭连接
 *         WebSocket.CLOSE(3): 已经关闭连接
 *     事件
 *         open: 在成功建立时触发
 *         error: 在发生错误时触发，连接不能持续
 *         close: 在关闭时触发
 *         	   事件对象属性
 *                 wasClean: boolean, 表示是否已经明确地关闭
 *                 code: 服务器返回的数值状态码
 *                 reason: 字符串，包含服务器发回的消息
 */
(function(){
	var socket = new WebSocket("ws://www.example.com/server.php");
	var message = {
		time: new Date(),
		text: "hello",
		clientId: "asdas123"
	};
	socket.send(JSON.stringify(message));
	socket.onopen = function(){
		console.log("begin");
	};
	socket.onerror = function () {
		console.log("error");
	};
	socket.onclose = function(event){
		console.log(event.wasClean + event.code + event.reason);
	};
})();