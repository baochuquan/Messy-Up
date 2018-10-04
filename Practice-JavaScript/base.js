/**
 * use strict
 */

/**
 * Base Type : 5
 * ==================
 * 1. undefined
 * 2. boolean
 * 3. null
 * 4. string
 * 5. number
 * -------------------
 * typeof xxx == "string/number/boolean/undefined/null"
 * -------------------
 * number
 *     NaN, Infinity, -Infinity
 *     Number(), parseInt(), parseFloat()
 * string
 *     toString(), String()
 * object
 *     constructor:                         the function which created this object;
 *     hasOwnProperty(propertyName):        ;  
 *     isPrototypeOf(object): 				      ;
 *     propertyIsEnumerable(propertyName): 	;
 *     toLocaleString(): 					          return string expression of object(locale);
 *     toString(): 							            return string expression of object;
 *     valueOf(): 							
  */
 
/**
 * Reference Type : object
 * ==================
 * 1. Array
 * 2. Date
 * 3. RegExp
 * 4. Function
 * ------------------
 * xx instanceof Object/Array/RegExp/...
 * ------------------
 * try-catch
 * with(xxx)
 */
 
/**
 * Object 
 * ------------------
 * ------------------
 * create
 *     1. new Object();
 *     2. { pro1: val1, pro2 : val2 }
 * ------------------
 */

/**
 * Array
 * ==================
 * create
 *     1. new Array();
 *     2. ["x", "y", "z"]
 * ------------------
 * convert function:
 *     1. valueOf():            return array;
 *     2. toString(): 			    return string, with "," between elements;
 *     3. toLocaleString(): 	  return string, with "," between elements;
 *     4. join(): 				      return string, with "anychar" between elements;
 * ------------------
 * stack function:
 *     1. push(): 				      return new length;
 *     2. pop(): 				        return the deleted item;
 * ------------------
 * queue function:
 *     1. push(): 				      return new  length;  
 *     2. shift(): 				      return the deleted item(the first item);
 *     3. unshift(): 			      return new length;  add some items in first position;
 * ------------------
 * reorder function:
 *     1. reverse(): 		        return new array;  make the array reverse
 *     2. sort([compare]): 		  return new array;  sort
 * ------------------
 * operate function:
 *     1. concat([item],[array],...):           return new array;  add paras to the end; initial array unchange
 *     2. slice(start, [end]): 				          return new array;  exclude the end item;
 *     3. splice():
 *         1. splice(start, n): 			          delete n items from start
 *         2. splice(start, 0, item1, ...):	    insert item1... from start 
 *         3. splice(start, x, item1, ...):     replace: delete x items from start, then insert items1...
 * ------------------
 * postion function:
 *     1. indexOf([start], val): 			          return the matched postion;
 *     2. lastIndexOf([start], val): 		        return the matched postion;
 * ------------------
 * iteration function:
 *     1. every(func): 						              return true if every item is ok;
 *     2. filter(func): 					              return array, its items are ok;
 *     3. forEach(func):					              no return;
 *     4. map(func): 						                return reusult array;
 *     5. some(func): 						              return true if some item is ok;
 * ------------------
 * merge function:
 *     1. reduce(func(prev, cur, index, array), [base]): 			
 *     2. reduceRight(func(prec, cur, index, array), [base]):
 */

/**
 * Data
 * ==================
 * create:
 *     1. new Date([ms]);	        return current time & date, if para is string, call Data.parse/UTC auto.
 *     2. Date.parse(str): 		    return ms 
 *         format:
 *             1. 6/3/2004
 *             2. January 12, 2004
 *             3. Tue May 25 2005 00:00:00 GMT-0700
 *             4. 2004-05-25T00:00:00
 *     3. Date.UTC(str): 		      return ms
 *         format:
 *             1. year, month(0), [day], [hour], [minute], [second], [ms]
 * ------------------
 * date format function:
 *     1. toDateString(): 
 *     2. toTimeString(): 
 *     3. toLocaleString():
 *     4. toLocaleTimeString():
 *     5. toUTCString():    
 */

/**
 * RegExp
 * ==================
 * var expression = / pattern / flags
 * ------------------
 * flags:
 *     1. g: 		global
 *     2. i: 		case-insensitive
 *     3. m: 		multiline
 * ------------------
 * special char
 *     () [] {} \ ? $ * + . ^ |
 * ------------------
 * create
 *     1. new RegExp("[bc]at", "i");
 *     2. pat = /[bc]at/i
 * ------------------
 * test
 *     1. test(str)
 * ------------------
 * instance property
 *     1. global:             if set g
 *     2. ignorecase:         if set i
 *     3. lastIndex: 	        next index to start
 *     4. multiline: 	        if set m
 *     5. source: 		        string expression of regexp
 * ------------------
 * instance function
 *     1. exec(str): 			    return the array of informations of first macthes
 *         1. index: 			    the match position
 *         2. input: 			    str
 *     2. toString(): 			  return string expression of regexp
 *     3. toLocaleString(): 	return string expression of regexp
 * ------------------
 * constructor proprety
 *     1. input/$_: 			    the last str tested
 *     2. lastMatch/$&: 		  the last matched item
 *     3. lastParen/$+: 		  the last capture group
 *     4. leftContext/$`: 		the string before lastMatch
 *     5. multiline/$*: 		  if multiline used
 *     6. rightContext/$': 		the string after lastMatch
 */

/**
 * Function
 * ==================
 * internal property
 *     1. arguments: 			        the para array
 *         1. callee: 			      pointer, point to the function which have arguments
 *     2. this: 				
 *     3. caller: 				        the function which called current function
 * ------------------
 * function property & function
 *     1. length: 				        the count of para the function want to receive
 *     2. prototype: 
 *     3. apply(this, array): 	  other.apply(this, arguments)
 *     4. call(this, ...): 		    other.call(this, para1, para2, ...)
 *     5. bind(obj): 			        other.bind(obj);  bind the obj's this to other function
 */

/**
 * Base Package Type : 3 Special Reference Type
 * ==================
 * 1. Boolean
 * 2. Number
 * 3. String
 * ------------------
 * PS: when read a base type value, the backward will create a base package type object, so it can use somefunctions.
 * step(for example):
 * 	   1. create an instance of string
 * 	   2. use substring()
 * 	   3. destroy the instance
 * ------------------
 * PS(for example): 
 *     1. Number():           typeof xxx is number
 *     2. new Number():       typeof xxx id object
 */

/**
 * Boolean
 * ==================
 */

/**
 * Number
 * ==================
 * function
 *     1. toFixed():          return string expression of number
 *     2. toExponential(): 	  return e expression of number
 *     3. toPrecision(): 	    return string expression of number , para means all the number
 */

/**
 * String
 * ==================
 * char function
 *     1. charAt(pos): 			  return the char
 *     2. charCodeAt(pos): 		return the code of char
 * ------------------
 * string operate function
 *     1. concat(str,...): 		return the new string
 *     2. slice(s, e): 			  return the new string
 *     3. substring(s, e): 		return the new string
 *     4. substr(s, n): 		  return the new string
 * ------------------
 * string position function
 *     1. indexOf(str, [s]):      return the index
 *     2. lastIndexOf(str, [s]): 	return the index
 * ------------------
 * trim() function
 *     1. trim():
 *     2. trimLeft():
 *     3. trimRight():
 * ------------------
 * string case convert function
 *     1. toLowerCase():
 *     2. toLocaleLowerCase():
 *     3. toUpperCase():
 *     4. toLocaleUpperCase():
 * ------------------
 * string pattern match function
 *     1. match(pattern):  					        return array like exec()
 *     2. search(pattern): 					        return the first matched item index
 *     3. replace(pattern/str, str/func): 	return new 
 *     4. split(str,[n]):                   reutrn array
 * ------------------
 * localeCompare() function
 *     1. localeCompare(str):               return -1 if text[i] < str[i]...
 * ------------------
 * fromCharCode() function
 *     1. fromCharCode(cd1, cd2,...): 		 	return string
 * ------------------
 * HTML function
 *     1. ...
 */

/**
 * Internal Object
 * ==================
 * Global, Math
 */

/**
 * Global
 * ==================
 * function
 *     1. isNaN():
 *     2. isFinite():
 *     3. parseInt():
 *     4. parFloat():
 *     ....
 * ------------------
 * URI function
 *     1. encodeURI(): 
 *     2. encodeURIComponent(): 			encode any unstandard char
 *     3. decodeURI():
 *     4. decodeURIComponent():
 * ------------------
 * eval() function
 *     1. eval(str): 						      excute the string as code
 * ------------------
 * Global property 
 *     1. undefined
 *     2. NaN
 *     3. Infinity
 *     4. Object
 *     5. Array
 *     6. Function
 *     7. Boolean
 *     8. String
 *     9. Number
 *     10.Date
 *     11.RegExp
 *     12.Error
 *     13.EvalError
 *     14.RangeError
 *     15.ReferenceError
 *     16.SyntaxError
 *     17.TypeError
 *     18.URIError
 * ------------------
 * window object
 *     treat window object as Global in navigator environment
 */

/**
 * Math
 * ==================
 * Math property
 *     1. Math.E
 *     2. Math.LN10
 *     3. Math.LN2
 *     4. Math.LOG2E
 *     5. Math.LOG10E
 *     6. Math.PI
 *     7. Math.SQRT1_2
 *     8. Math.SQRTR2
 * ------------------
 * min & max function
 *     1. Math.min()
 *     2. Math.max()
 * ------------------
 * rounding function
 *     1. Math.ceil()
 *     2. Math.floor()
 *     3. Math.round()
 * ------------------
 * random() function
 *     1. Math.random()
 * ------------------
 * other function
 *     1. Math.abs() 
 *     2. Math.exp()
 *     3. Math.log()
 *     4. Math.pow()
 *     5. Math.sqrt()
 *     6. Math.acos()
 *     7. Math.asin()
 *     8. Math.atan()
 *     9. Math.atan2()
 *     10.Math.sin()
 *     11.Math.tna()
 *     12.Math.cos()
 */

/**
 * Object property
 * ==================
 * data attribute
 *     1. [[configurable]]: 		default true: if can delete property and redefine or modify to accessor attribute
 *     2. [[enumerablr]]: 			default true: if can return property through for-in
 *     3. [[writable]]:         default true: if can modify property value
 *     4. [[value]]: 				    default undefined: the value of property
 * ------------------
 * modify attribute function
 *     1. Object.defineProperty(obj, pro, des): 
 *         for example:
 *             Object.defineProperty(obj, "name", {
 *                 writable: false,
 *                 value: "Nicholas"
 *             })
 *     PS: if des not mentioned other attribute, they will be set false default
 * ------------------
 * accessor attribute
 *     1. [[configurable]]: 		default true: if can delete property and redefine or modify to data attribute
 *     2. [[enumerable]]: 			default true: if can return property through for-in
 *     3. [[get]]: 					    default undefined: the function called when read attribute
 *     4. [[set]]: 					    default undefined: the function called when write attribute
 * ------------------
 * define many attribute
 *     1. Object.defineProperties(obj1, obj2): 
 * ------------------
 * read attribute of property
 *     1. Object.getOwnPropertyDescriptor(obj, pro):
 */


 /**
  * DOM 
  * ------------------------------------------------------------------------------------------------------------
  * 1. Document
  * 2. ELement
  * 3. Text
  * 4. Comment
  * 5. CDATASection
  * 6. DocumentType
  * 7. DocumentFragment
  * 8. Attr
  */

/**
 * Node Type
 * ==================
 * nodeType property
 *     1. Node.ELEMENT_NODE						      1
 *     2. Node.ATTRIBUTE_NODE					      2
 *     3. Node.TEXT_NODE						        3
 *     4. Node.CDATA_SECTION_NODE	          4
 *     5. Node.ENTITY_REFERENCE_NODE        5
 *     6. Node.ENTITY_NODE                  6
 *     7. Node.PROCESSING_INSTRUCTION_NOE		7
 *     8. Node.COMMENT_NODE						      8
 *     9. Node.DOCUMENT_NODE					      9
 *     10.Node.DOCUMENT_TYPE_NODE				    10
 *     11.Node.DOCUMENT_FRAGMENT_NODE			  11
 *     12.Node.NOTIATION_NODE					      12
 * ------------------
 * node property
 *     1. nodeName: 
 *     2. nodeValue:
 *     3. childNodes: 		                  NodeList object; 
 *     4. parentNode:
 *     5. childNodes:
 *     6. nextSibing:
 *     7. previousSibling:
 *     8. firstChild:
 *     9. lastChild:
 *     10.ownerDocument: 	                  pointer to the unique document node
 * ------------------
 *     1. hasChildNodes(): 	true/false
 * ------------------
 * operate nodes
 *     1. appendChild(): 						        add a new node in the end of childNodes(NodeList)
 *     2. insertBefore(): 	
 *         1. insertBefore(newNode, null): 	be the lastChild
 *     3. replaceChild(new, old): 				
 *     4. removeChild():
 * ------------------
 * other function
 *     1. cloneNode(true/false): 				    true: recursive; false: node itself
 *     2. normalize(): 							        deal text node, if it has no content or two text node 
 */

/**
 * 1. Document Type
 * ==================
 * document : as an instanceof HTMLDocument
 * ------------------
 * characteristic
 *     1. nodeType: 		  9
 *     2. nodeName: 		  #document
 *     3. nodeValue: 		  null
 *     4. parentNode: 		null
 *     5. ownerDocument:	null
 *     6. childNodes: 		DocumentType(0/1), Element(0/1), ProcessingInstruction, Comment
 * ------------------
 * property
 *     1. documentType: 	childNodes-><html>
 *     2. body: 			    <body>
 *     3. doctype: 			  <!DOCTYPE>
 * ------------------
 * document information
 *     1. title: 			    <title>
 *     2. URL: 				    URL
 *     3. domain: 			  domain name;  settable: to loose, not tight
 *     4. reference: 		  the URL of the previous page(linked to current page)
 * ------------------
 * search element
 *     1. getElementById():
 *     2. getElementsByTagName(): 	return HTMLCollection, like NodeList
 *         1. namedItem(str): 		  a function of HTMLCollection
 *     3. getElementsByName(): 		  return HTMLCollection, like NodeList
 * ------------------
 * special set (HTMLCollection object)
 *     1. document.anchors: 		return <a>
 *     2. document.applets: 		return <applets>
 *     3. document.forms: 			return <form>
 *     4. document.images: 			return <img>
 *     5. document.links: 			return <a> with href
 * ------------------
 * DOM conherence check
 *     1. document.implementation.hasFeature("DOM func", "version"): 	return true/false
 * ------------------
 * docuemnt write
 *     1. write(context): 			
 *     2. writeln(context): 		write "\n" at the end auto.
 *     3. open():
 *     4. close():
 */

/**
 * 2. Element Type
 * ==================
 * characteristic
 *     1. nodeType: 		  1
 *     2. nodeName: 		  tagName
 *     3. nodeValue: 		  null
 *     4. parentNode: 		Document/Element
 *     5. childNodes: 		Element, Text, Comment, ProcessingInstruction, CDATASection, EntityReference
 * ------------------
 * HTML element attribute
 *     1. id: 
 *     2. title
 *     3. lang
 *     4. dir
 *     5. className
 * ------------------
 * attribute operation
 *     1. getAttribute("id/title/lang/dir/class"): 		it can also get selfdefined attribute
 *         1. style: 									  get CSS text
 *         2. onclick: 									code string
 *     2. setAttribute("id/title/lang/dir/class"): 		it can also set selfdefined attribute
 *     3. removeAttribute():
 *     4. attributes
 * ------------------
 * attributes property (NamedNodeMap)
 *     1. getNamedItem(name): 		return nodeName equals to name
 *     2. removeNamedItem(name): 	remove the node whose nodeName equals to name
 *     3. setNamedItem(node): 		add node to NamedNodeMap, nodeName property as index
 *     4. item(pos):              return the node at pos
 * ------------------
 * create element
 *     1. document.createElement():   
 *     2.   
 */

/**
 * 3. Text Type
 * ==================
 * characteristic
 *     1. nodeType:       3
 *     2. nodeName:       "#text"
 *     3. nodeValue:      text
 *     4. parentNode:     Element Type
 * ------------------
 * text operation
 *     1. appendData(text):                 append data to the end of the node
 *     2. deleteData(offset, count):        delete count chars from offset
 *     3. insertData(offset, text):         insert text in offset
 *     4. replaceData(offset, count, text): replace count chars from offset with text
 *     5. splitText(offset):                split into two text node at the position of offset
 *     6. substringData(offset, count):     get subtring from offset to offset + count
 * ------------------
 * create function
 *     1. document.createTextNode():
 * ------------------
 * merge text node
 *     1. normalize():          merge text node
 * ------------------
 * split text node
 *     1. splitText(pos):       split text into [0-pos) & [pos, end)
 */

/**
 * 4. Comment Type
 * ==================
 * characteristic
 *     1. nodeType:       8
 *     2. nodeName:       #comment
 *     3. nodeValue:      comment content
 *     4. parentNode:     Document / Element
 * ------------------
 * create function
 *     1. document.createComment():
 */

/**
 * 5. CDATASection Type      (only for XML)
 * ==================
 * characteristic
 *     1. nodeType:       4
 *     2. nodeName:       #cdata-section
 *     3. nodeValue:      content in CDATA
 *     4. parentNode:     Document / Element
 * ------------------
 * create function
 *     1. document.createCDataSection():
 */

/**
 * 6. DocumentType Type
 * ==================
 *     1. nodeTpye:       10
 *     2. nodeName:       doctype name
 *     3. nodeValue:      null
 *     4. parentNode:     Document
 * ------------------
 * property
 *     1. name:           document type name
 *     2. entities:       NamedNodeMap
 *     3. notations:      notations
 */

/**
 * 7. DocumentFragment Type
 * ==================
 * characteristic
 *     1. nodeType:       11
 *     2. nodeName:       #document-fragment
 *     3. nodeValue:      null
 *     4. parentNode:     null
 *     5. childNode:      Element / ProcessingInstruction / Comment / Text / CDATASection / EntityReference
 * ------------------
 * create function
 *     1. document.createDocumentFragment(): 
 */

/**
 * 8. Attr Type
 * ==================
 * characteristic
 *     1. nodeType:       2
 *     2. nodeName:       attribute name
 *     3. nodeValue:      value of attribute
 *     4. parentNode:     null
 * ------------------
 * property
 *     1. name:           nodeName
 *     2. value:          nodeValue
 *     3. specified:      boolean
 * ------------------
 * create function
 *     1. document.createAttribute():
 * ------------------
 * function
 *     1. setAttributeNode():
 *     2. getAttributeNode():
 */

/**
 * table 
 * ==================
 * property
 *     1. caption
 *     2. tBodies:        HTMLCollection of <tbody>
 *     3. tFoot:          
 *     4. tHead
 *     5. rows:           HTMLCollection of all rows
 *     6. cells
 * ------------------
 * functions
 *     1. createTHead():
 *     2. createTFoot():
 *     3. createCaption():
 *     4. deleteTHead():
 *     5. deleteTFoot():
 *     6. deleteCaption():
 *     7. deleteRow(pos):
 *     8. deleteCell(pos):
 *     9. insertRow(pos):
 *     10.insertCell(pos):
 */

/**
 * NodeList
 * ==================
 * NodeList, NamedNodeMap, HTMLCollection
 */

/**
 * Selectors API
 * ==================
 *     1. querySelector(): 
 *     2. querySelectorAll():
 *     3. matchesSelector():      return true / false
 */

/**
 * Element Traversal API
 * ==================
 *     1. childElementCount:      return child element count, no include text node or comment
 *     2. firstElementChild:      point to first child 
 *     3. lastElementChild:       point to last child
 *     4. previousElementSibling: 
 *     5. nextElementSibling:   
 */

/**
 * HTML5
 * ==================
 *     1. getElementsByClassName():       return NodeList
 * ------------------
 *     1. classList:                      instance of DOMTokenList
 *         1. add(value):
 *         2. contains(value):
 *         3. remove(value):
 *         4. toggle(value):
 * ------------------
 * focus management
 *     1. document.activeElement:  
 *     2. focus():                    get focus
 *     3. document.hasFocus():        return true / false;
 * ------------------
 * HTMLDocument
 *     1. readyState:             loading / complete
 *     2. document.compatMode:    standard mode: CSS1Compat ; Hybrid mode: BackCompat
 *     3. head:     
 * ------------------
 * char set
 *     1. document.charset: 
 *     2. document.defaultCharset:
 * ------------------
 * self defined data property
 *     1. data-
 *     2. dataset:                instance of DOMStringMap
 * ------------------
 * insert tag
 *     1. innerHTML: 
 *     2. outerHTML:                          include element it self
 *     3. insertAdjacentHTML(para1, para2):   
 *         1. beforebegin: 
 *         2. afterbegin:
 *         3. beforeend:
 *         4. afterend:  
 * ------------------
 * scrollIntoView() function
 *     1. scrollIntoView(): 
 * ------------------
 * document mode
 *     1. Edge: 
 *     2. EmulateIE9:
 *     3. EmulateIE8:
 *     4. EmulateIE7:
 *     5. 9
 *     6. 8
 *     7. 7
 *     8. 5
 *     9. ...
 *     10. document.documentMode
 * ------------------
 * children property
 * ------------------
 * contains() function
 *     1. contains():
 *     2. compareDocumentPosition():
 * ------------------
 * insert text
 *     1. innerText: 
 *     2. outerText:
 * ------------------
 * scroll
 *     1. scrollIntoViewIfNeeded(alignCenter):
 *     2. scrollByLines(lineCount):
 *     3. scrollByPages(pageCount):
 *     
 */
 
 /**
 * Event
 * ------------------------------------------------------------------------------------------------------------
 *     1. Event bubbling:     IE
 *     2. Event capturing:    Netscape
 *     3. DOM Event flow
 */
 
 /**
 * Event Handler
 * =================
 * HTML event handler
 *     1. onclick="XXX"
 * -----------------
 * DOM0 event handler
 *     1. xxx.onclick = function(){};
 * -----------------
 * DOM2 event handler
 *     1. addEventListener(eType, handler, boolean):     true: event capture; false: event bubbling
 *     2. removeEventListener(eType, handler, boolean):  the same with addEventListener
 * -----------------
 * IE event handler
 *     1. attachEvent(onclick, handler): 
 *     2. detachEvent(onclick, handler):
 * -----------------
 * Cross-browser event handler  (these two functions belongs to EventUtil obj)
 *     1. addHandler(element, eType, handler): 
 *     2. removeHandler(element, eType, handler): 
 */

/**
 * Event Object
 * =================
 * property / function
 *     1. bubbles:                    Boolean       if event is bubbling
 *     2. cancelable:                 Boolean       if can cancel event default behavior
 *     3. currentTarget:              Element       the element being handling
 *     4. defaultPrevented:           Boolean       true: preventDefault() has been called
 *     5. detail:                     Integer       event info 
 *     6. eventPhase:                 Integer       stage: 1:capturing; 2:in target; 3:bubbling
 *     7. preventDefault()            Function      cancel event default behavior
 *     8. stopImmediatePropagation(): Function      cancel event capturing or bubbling, event handler cannot be called
 *     9. stopPropagation():          Function      cancel event capturing or bubbling. 
 *     10.target:                     Element       target
 *     11.trusted:                    Boolean       true: create by browser; false: create by JS
 *     12.type:                       String        event type
 *     13.view:                       AbstractView  window
 *     
 */

/**
 * Event Type
 * =================
 *     1. UI event:
 *     2. focus event:
 *     3. mouse event:
 *     4. scroll event:
 *     5. text event:
 *     6. keyboard event:
 *     7. composition event:
 *     8. mutation event:
 *     9. mutation name event:
 */

/**
 * UI event
 * =================
 *     1. DOMActivate:  表示元素已经被用户操作（通过鼠标或键盘）激活
 *     2. load:         表示加载完毕
 *     3. unload:       当页面完全卸载后在window上面触发...
 *     4. abort:        用户停止下载过程时，如果嵌入的内容没有加载完，则在<object>元素上面触发
 *     5. error:        
 *     6. select:
 *     7. resize:
 *     8. scroll:
 */

/**
 * Focus event
 * =================
 *     1. blur
 *     2. DOMFocusIn
 *     3. DOMFocusOut
 *     4. focus
 *     5. focusin
 *     6. focusout
 */

/**
 * mouse & scroll event
 * =================
 *     1. click: 
 *     2. dbclick
 *     3. mousedown
 *     4. mouseenter
 *     5. mouseleave
 *     6. mousemove
 *     7. mouseout
 *     8. mouseover
 *     9. mouseup
 *     10.mousewheel
 * -----------------
 *     1. clientX/clientY
 *     2. pageX/pageY
 *     3. screentX/screenY
 * -----------------
 *     1. shiftKey:     Shift
 *     2. ctrlKey:      Ctrl
 *     3. altKey:       Alt
 *     4. metaKey:      Meta(windows / command)
 */

/**
 * keyboard & text event
 * =================
 *     1. keydown:
 *     2. keypress:
 *     3. keyup:
 *     4. textInput:
 */

/**
 * Composition event
 * =================
 *     1. compositionstart: 
 *     2. compositionupdate: 
 *     3. compositionend:
 */

/**
 * Mutation event
 * =================
 *     1. DOMSubstreeModified:
 *     2. DOMNodeInserted:
 *     3. DOMNodeRemoved
 *     4. DOMNodeInsertedIntoDocument
 *     5. DOMNodeRemovedFromDocument
 *     6. DOMAttrModified:
 *     7. DOMCharacterDataModified:
 */

/**
 * HTML5 event
 * =================
 *     1. contextmenu:
 *     2. beforeunload:
 *     3. DOMContentLoaded:
 *     4. readystatechange:
 *         1. uninitialized:
 *         2. loading:
 *         3. loaded:
 *         4. interactive:
 *         5. complete
 *     5. pageshow & pagehide
 *         1. persisted
 *     6. hashchange
 */

/**
 * Simulate Event
 * =================
 * DOM event simulation
 *     1. document.createEvent(eType):
 *         1. UIEvents
 *         2. MouseEvents
 *         3. MutationEvents
 *         4. HTMLEvents
 * -----------------
 */

/**
 * From script
 * =================
 * HTMLFormElement
 *     1. acceptCharset:
 *     2. action
 *     3. elements
 *     4. enctype
 *     5. length
 *     6. method
 *     7. name
 *     8. reset()
 *     9. submit()
 *     10.target
 */

/**
 * HTML5 Script Programming
 * -----------------------------------------------------------------------------------------------------------
 */

/**
 * Cross-document messaging (XDM)
 * =================
 *     1. postMessage()  
 */

/**
 * Drag
 * =================
 *     1. dragstart
 *     2. drag
 *     3. dragend
 *     4. dragenter
 *     5. dragover
 *     6. dragleave
 *     7. drop
 * -----------------
 * dataTransfer
 *     1. getData()
 *     2. setData()
 *     3. dropEffect:
 *         1. none
 *         2. move
 *         3. copy
 *         4. link
 *     4. effectAllowed:      
 *         1. uninitialized
 *         2. none
 *         3. copy
 *         4. link
 *         5. move
 *         6. copylink
 *         7. copyMove
 *         8. linkMove
 *         9. all
 */

/**
 * HTTP Header
 * =================
 * Request Header
 *     1. Accept:           content type that browser can handle
 *     2. Accept-Charset:   charset that browser can display
 *     3. Accept-Encoding:  encoding that browser can handle
 *     4. Accept-Language:  current language of browser
 *     5. Connection:       connection type of browser-server
 *     6. Cookie:           cookie of current page
 *     7. Host:             domain of request page
 *     8. Reference:        URI of request page
 *     9. User-Agent:       user-agent string of browser
 * -----------------
 * self define
 *     1. setRequestHeader(headerName, headerValue)
 *     2. getResponseHeader(headerName)
 *     3. getAllResponseHeaders()
 * -----------------
 * GET request
 *     1. 
 */

 /**
  * Progress Event
  * ================
  *    1. loadstart:        triggered when receive the first byte
  *    2. progress:         during receiving
  *        1. lengthComputable:     true/false, if progress info can be used
  *        2. position:             bytes has been received
  *        3. totalSize:            bytes that Content-Length defined
  *    3. error:            triggered when request error
  *    4. abort:            triggered when terminate connect due to abort()
  *    5. load:             triggered when receive complete response data
  *    6. loadend:          triggered at the end or after error, abort, load events
  */