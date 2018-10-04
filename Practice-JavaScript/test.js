/**
 * Funtion: parse URI
 * @return {object}
 */
function getQueryStringArs () {
	var qs = (location.search.length > 0 ? location.search.substring(1) : ""),
		args = {},
		items = qs.length > 0 ? qs.split("&") : [],
		item = null,
		name = null,
		value = null,
		i = 0,
		len = items.length
	;
	for(i = 0; i < len; i++){
		item = items[i].split("=");
		name = decodeURIComponent(item[0]);
		value = decodeURIComponent(item[1]);
		if(name.length){
			args[name] = value;
		}
	}
	return args;
}

/**
 * Function: to check navigator plugin
 * @param  {string}
 * @return {Boolean}
 */
function hasPlugin (name) {
	name = name.toLowerCase();
	for(var i = 0; i < navigator.plugins.length; i++){
		if(navigator.plugin[i].name.toLowerCase().indexOf(name) >= 0){
			return true;
		}
	}
	return false;
}

/**
 * Funtion: to check IE navigator plugin
 * @param  {string}
 * @return {Boolean}
 */
function hasIEPlugin(name){
	try{
		new ActiveXObject(name);
		return true;
	} catch (ex) {
		return false;
	}
}

/**
 * Function: to check navigator's Flash
 * @return {Boolean}
 */
function hasFlash () {
	var result = hasPlugin("Flash");
	if(!result){
		result = hasIEPlugin("ShockwaveFlash.ShockwaveFlash");
	}
	return result;
}

/**
 * Function: to check navigator's QuickTime
 * @return {Boolean}
 */
function hasQuickTime () {
	var result = hasPlugin("QuickTime");
	if(!result){
		result = hasIEPlugin("QuickTime.QuickTime");
	}
	return result;
}

/**
 * Function: to convert NodeList to Array
 * @param  {Array}
 * @return {Array}
 */
function convertToArray (nodes) {
	var array = null;
	try{
		array = Array.prototype.slice.call(nodes, 0);
	} catch(ex) {
		array = new Array();
		for (var i = 0, len = nodes.length; i < len; i++) {
			array.push(nodes[i]);
		}
	}
	return array;
}

/**
 * Funtion: to return all attribute of element
 * @param  {[type]} element [description]
 * @return {[type]}         [description]
 */
function outputAttributes (element) {
	var pairs = new Array(),
		attrName,
		attrValue,
		i,
		len;
	for (i = 0, len = element.attributes.length; i < len; i++) {
		attrName = element.attributes[i].nodeName;
		attrName = element.attributes[i].nodeValue;
		pairs.push(attrName += "=\"" + attrValue + "\"");
	};
	return pairs.join(" ");
}

/**
 * Function: to load a script
 * @param  {[type]} url [description]
 * @return {[type]}     [description]
 */
function loadScript(url){
	var script = document.createElement("script");
	script.src = url;
	script.type = "text/javascript";
	document.body.appendChild(script);
}

function loadScriptString(code){
	var script = document.createElement("script");
	script.type = "text/javascript";
	try{
		script.appendChild(document.createTextNode(code));
	} catch(err){
		script.text = code;
	}
	document.body.appendChild(script);
}

function loadStyleString(css) {
	var style = document.createElement("style");
	style.type = "text/css";
	try{
		style.appendChild(document.createTextNode(css));
	} catch(erro){
		style.cssText = css;
	}
	document.getElementsByTagName("head")[0].appendChild(style);
}

function createTable () {
	var table = document.createElement("table");
	table.border = "1";
	table.width  = "100%";

	var tbody = document.createElement("tbody");
	tbody.rows[0].insertCell(0);
	tbody.rows[0].cells[0].appendChild(document.createTextNode("Cell 1,1"));
	tbody.rows[0].insertCell(1);
	tbody.rows[0].cells[1].appendChild(document.createTextNode("Cell 1,2"));

	tbody.rows[1].insertCell(0);
	tbody.rows[1].cells[0].appendChild(document.createTextNode("Cell 2,1"));
	tbody.rows[1].insertCell(1);
	tbody.rows[1].cells[1].appendChild(document.createTextNode("Cell 2,2"));

	document.body.appendChild(table);
}

function contains (refNode, otherNode) {
	if (typeof refNode.contains == "fucntion" && (!client.engine.webkit || client.engine.webkit >= 522)) {
		return refNode.contains(otherNode);
	} else if (typeof refNode.compareDocumentPosition == "function") {
		return !!(refNode.compareDocumentPosition(otherNode) & 16);
	} else {
		var node = otherNode.parentNode;
		do {
			if (node === refNode) {
				return true;
			} else {
				node = node.parentNode;
			}
		} while (node !== null);
		return false;
	}
}

(function () {
	function tabForward (event) {		
		var target = event.target;
		if(target.value.length == target.maxLength){
			var form = target.form;
			for (var i = 0, len = form.elements.length; i < len; i++) {
				if(form.elements[i] == target) {
					if(form.elements[i+1]){
						form.elements[i+1].focus();
					}
					return;
				}
			};
		}
	}
})()
/*
function serialize (form) {
	var parts = [],
	field = null,
	i,
	len,
	j,
	optLen,
	option,
	optValue;
	for(i = 0, len=form.elements.length; i < len; i++){
		field = form.elements[i];
		switch(field.type){
			case "select-one":
			case "select-multiple":
			if (field.name.length) {
				for(j = 0, optLen = field.options.length; j < optLen; j++){
					option = field.options[i];
					if(option.selected){
						optValue = "";
						if(option.hasAttribute){
							optValue = (option.hasAttribute("value")) ? option.value : option.text;
						} else {
							optValue = (option.attributes["value"].specified ? option.value : option.text);
						}
						parts.push(encodeURIComponent(field.name) + "=" + encodeURIComponent(optValue));
					}
				}
			}
			break;
			case: undefined:
			case: "file":
			case: "submit":
			case: "reset":
			case: "button":
			break;
			case: "radio":
			case: "checkbox":
			if(!field.checked){
				break;
			}
			default:
			if(field.name.length){
				parts.push(encodeURIComponent(field.name) + "=" + encodeURIComponent(field.value));
			}
		}
	}
	return parts.join("&");
}
*/

(function(){
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function(){
		if(xhr.readyState == 4){
			if(xhr.status >= 200 && xhr.status < 300 || xhr.status == 304){
				console.log(xhr.responseText);
			} else {
				console.log("Failed");
			}
		}
	}
	xhr.open("post", "xxx.php", true);
	xhr.timeout = 1000;
	xhr.ontimeout = function () {
		alert("xxx");
	}
	xhr.overrideMimeType("text/xml");
	var form = document.forms[0];
	xhr.send(new FormData(form));
})()