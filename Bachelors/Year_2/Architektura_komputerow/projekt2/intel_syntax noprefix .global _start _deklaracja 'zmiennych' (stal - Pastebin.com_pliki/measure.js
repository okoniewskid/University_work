(function u(g,d,k){function h(b,r){if(!d[b]){if(!g[b]){var e="function"==typeof require&&require;if(!r&&e)return e(b,!0);if(l)return l(b,!0);e=Error("Cannot find module '"+b+"'");throw e.code="MODULE_NOT_FOUND",e;}e=d[b]={a:{}};g[b][0].call(e.a,function(d){var e=g[b][1][d];return h(e?e:d)},e,e.a,u,g,d,k)}return d[b].a}for(var l="function"==typeof require&&require,f=0;f<k.length;f++)h(k[f]);return h})({1:[function(q,g){g.a={r:"v294254/"}},{}],2:[function(q,g){var d=q("../utils"),k=q("../cache_buster");
g.a={g:d.protocol+"asset.pagefair.com",M:d.protocol+"asset.pagefair.net",P:"undefined"!==typeof bm_cache_buster?bm_cache_buster:k.r,h:"",O:"",L:bm_website_code,$:d.protocol+("undefined"!==typeof bm_static_location?bm_static_location:"pagefair.com"),ba:d.protocol+("undefined"!==typeof bm_website_location?bm_website_location:"pagefair.com"),I:d.protocol+("undefined"!==typeof bm_stats_location?bm_stats_location:"stats.pagefair.com"),N:d.protocol+("undefined"!==typeof bm_ads_location?bm_ads_location:
"adfeed.pagefair.net")}},{"../cache_buster":1,"../utils":6}],3:[function(q,g){var d=q("../utils");g.a=function(k){function h(b,r){b=k.h+b;for(var e=b+"=",p=document.cookie.split(/[;&]/),h="null",l=0;l<p.length;l++){for(var f=p[l];" "===f.charAt(0);)f=f.substring(1,f.length);0===f.indexOf(e)&&(h=f.substring(e.length,f.length))}e=h;"null"==h?e=null:("string"==d.type(h)&&(e=h.replace(/___/g,";")),void 0!==r&&("ARRAY"==r?e=e.split(","):"INT"==r?e=parseInt(e):"BOOL"==r&&(e="true"==e)));return e}function l(d){d=
k.h+d;document.cookie=d+"=; expires=Mon, 20 Sep 2010 00:00:00 UTC; path=/"}function f(b,h,e){b=k.h+b;void 0===e&&(e=d.b.v);var f=h;null===h?f="null":(d.isArray(h)&&(f=h.join(",")),"string"===d.type(f)&&(f=f.replace(/;/g,"___")));l(b);document.cookie=b+"="+f+"; expires="+e.toUTCString()+"; path=/"}return{d:h,f:f,V:l,X:function(){var b=d.e("bm_dts");null!=b&&(b=d.K(b),b>d.b.now&&f("bm_donor",1,b));return null!=h("bm_donor")},A:function(){null!=d.e("bm_opted_out")&&f("bm_opted_out",1,d.b.o);return null!=
h("bm_opted_out")}}}},{"../utils":6}],4:[function(q,g){var d=q("../utils");g.a=function(k){function h(){if(d.u(m)===p&&!t){t=!0;for(var n=!1,c=d.c(m),b=0;b<c.length;b++){var f=c[b];0!=f.indexOf("ctrl_")&&(0!=f.indexOf("wl_")&&m[f])&&(n=!0)}c=n&&"NOT_BLOCKING"==s.n||!n&&"BLOCKING"==s.n;e.f("bm_last_load_status",n?"BLOCKING":"NOT_BLOCKING");void 0!==a&&jQuery.isFunction(a)&&a(n,m,c)}}function l(){function a(c){var n=d.c(m);0<d.k(n,"wl_i_hid")||(n=jQuery("#influads_block"),m.wl_i_hid=n.is(":hidden")?
1:0,m.wl_i_blk=c,n.remove(),h())}var c=document.createElement("IMG");d.browser.safari||d.browser.msie?setTimeout(function(){a(0)},1):(jQuery(c).load(function(){a(0)}),jQuery(c).error(function(){a(1)}));c.id="influads_block";c.style.width="1px";c.style.height="1px";c.style.top="-2000px";c.style.left="-2000px";document.body.appendChild(c);c.src=k.M+"/adimages/textlink-ads.jpg"}function f(){function a(n){var b=d.c(m);0<d.k(b,"s_rem")||(b=jQuery("#"+c),m.s_blk=n,b.remove(),h())}var c=d.j(),b=document.createElement("SCRIPT");
9>d.w||d.browser.safari||d.browser.mozilla?setTimeout(function(){a(0)},1):(jQuery(b).load(function(){a(0)}),jQuery(b).error(function(){a(1)}));b.id=c;b.type="text/javascript";document.getElementsByTagName("head")[0].appendChild(b);b.src=k.g+"/adimages/adsense.js"}function b(){var a=d.j(),c=document.createElement("IFRAME");c.id=a;c.className="ad_iframe2";c.style.display="block";c.style.border="none";c.style.width="1px";c.style.height="1px";c.style.top="-1000px";c.style.left="-1000px";c.src=k.g+"/adimages/ad.html";
document.body.appendChild(c);setTimeout(function(){var c=jQuery("#"+a);m.if_hid=c.is(":hidden")?1:0;c.remove();h()},1)}function g(){function a(b){var n=d.c(m);0<d.k(n,"i_hid")||(n=jQuery("#"+c),m.i_hid=n.is(":hidden")?1:0,m.i_blk=b,n.remove(),h())}var c=d.j(),b=document.createElement("IMG");d.browser.safari||d.browser.msie?setTimeout(function(){a(0)},1):(jQuery(b).load(function(){a(0)}),jQuery(b).error(function(){a(1)}));b.id=c;b.className="AdHere";b.style.width="1px";b.style.height="1px";b.style.top=
"-1000px";b.style.left="-1000px";document.body.appendChild(b);b.src=k.g+"/adimages/textlink-ads.jpg"}var e=q("../cookies")(k),p,s={n:e.d("bm_last_load_status")},m={},t=!1,a;return{H:function(d,c){t&&(t=!1,m={});a=c;!0==d?(p=6,l()):p=4;g();b();f()},s:s}}},{"../cookies":3,"../utils":6}],5:[function(q,g){var d=q("../utils");g.a=function(k){function h(b){b=d.B.parse(b).sample_frequency;b!=f.p&&l.f("bm_sample_frequency",b,d.b.i);d.m("pagefair_exp_id")&&(b=d.e("pagefair_exp_id"),jQuery("body").append('<div id="'+
b+'" style="display: none;"></div>'))}var l=q("../cookies")(k),f={C:l.d("bm_monthly_unique"),t:l.d("bm_daily_unique"),p:l.d("bm_sample_frequency","INT")};return{G:function(b,g,e){!0===l.A()&&(g.opted_out=1);b=f.p;e&&(b=g.p_false=1);e=!1;null===f.C&&(l.f("bm_monthly_unique",!0,d.b.l),e=!0);e&&(b=g.new_monthly=1);e=!1;null===f.t&&(l.f("bm_daily_unique",!0,d.b.i),e=!0);e&&(b=g.new_daily=1);d.m("pagefair_exp_id")&&(g.exp_id=d.e("pagefair_exp_id"));if(null!==b&&1<b){if(d.random()>1/b)return;g.smp=b}d.q(k.I+
"/stats/page_view_event/"+k.L+"/a.js",g,h,!0)},s:f,S:l}}},{"../cookies":3,"../utils":6}],6:[function(q,g){function d(a){var b="?";for(key in a)b+=encodeURIComponent(key)+"="+encodeURIComponent(a[key])+"&";return b.substring(0,b.length-1)}function k(a){a=a.split(".");for(var b=jQuery.fn.jquery.split("."),c=0;c<b.length;c++){b[c]=parseInt(b[c],10);a[c]=parseInt(a[c],10);if(b[c]>a[c])break;if(a[c]>b[c])return!1}return!0}function h(){return Math.random()}function l(a){return a in m}function f(a){var b=
[],c;for(c in a)a.hasOwnProperty(c)&&b.push(c);return b}function b(a){return null==a?String(a):s[Object.prototype.toString.call(a)]||"object"}var r="https:"==document.location.protocol?"https://":"http://",e=function(){var a=3,b=document.createElement("div"),c;do b.innerHTML="\x3c!--[if gt IE "+ ++a+"]><i></i><![endif]--\x3e",c=0<b.getElementsByTagName("i").length?!0:!1;while(c);return 4<a?a:void 0}(),p=function(){var a=window.navigator.userAgent,a=a.toLowerCase(),a=/(chrome)[ \/]([\w.]+)/.exec(a)||
/(webkit)[ \/]([\w.]+)/.exec(a)||/(opera)(?:.*version|)[ \/]([\w.]+)/.exec(a)||/(msie) ([\w.]+)/.exec(a)||0>a.indexOf("compatible")&&/(mozilla)(?:.*? rv:([\w.]+)|)/.exec(a)||[];matched={browser:a[1]||"",version:a[2]||"0"};p={};matched.browser&&(p[matched.browser]=!0,p.version=matched.version);p.Q?p.webkit=!0:p.webkit&&(p.safari=!0);return p}(),s=function(){var a={};jQuery.each("Boolean Number String Function Array Date RegExp Object".split(" "),function(b,c){a["[object "+c+"]"]=c.toLowerCase()});
return a}(),m=function(){request_params={};for(var a,b=window.location.href.slice(window.location.href.indexOf("?")+1).split("&"),c=0;c<b.length;c++)a=b[c].split("="),request_params[a[0]]=a[1];return request_params}(),t=function(){var a={};a.now=new Date;a.i=new Date(a.now.getTime());a.i.setHours(23,59,59,999);a.l=new Date(a.now.getFullYear(),a.now.getMonth()+1,0);a.l.setHours(23,59,59,999);a.J=new Date(a.now.getTime());a.J.setDate(a.now.getDate()+1);a.F=new Date(a.now.getTime());a.F.setDate(a.now.getDate()+
7);a.D=new Date(a.now.getTime());a.D.setDate(a.now.getDate()+14);a.o=new Date(a.now.getTime());a.o.setDate(a.now.getDate()+28);a.v=new Date(2030,11,31);return a}();g.a={protocol:r,w:e,browser:p,R:s,type:b,isArray:function(a){return"array"===b(a)},now:function(){return(new Date).getTime()},B:{parse:function(a){return void 0!==JSON?JSON.parse(a):jQuery.parseJSON(a)},stringify:function(a){var b;window.Prototype&&(b=Array.prototype.toJSON,delete Array.prototype.toJSON);a=JSON.stringify(a);window.Prototype&&
(Array.prototype.toJSON=b);return a}},k:function(a,b){return jQuery.grep(a,function(a){return a==b}).length},c:f,W:function(a){var b=[],c;for(c in a)a.hasOwnProperty(c)&&b.push(a[c]);return b},u:function(a){return f(a).length},Z:m,m:l,e:function(a){return l(a)?m[a]:null},b:t,K:function(a){return new Date(1E3*a)},aa:function(a){return encodeURIComponent(a)},j:function(){var a=(new Date).getTime();return"xxxxxxxx".replace(/[xy]/g,function(b){var c=(a+16*h())%16|0;a=Math.floor(a/16);return("x"==b?c:
c&7|8).toString(16)})},random:h,Y:k,T:d,q:function(a,b,c,e){b=b||{};e=e||!1;c=c||null;var f=!0;if("undefined"!==typeof XMLHttpRequest&&"withCredentials"in new XMLHttpRequest&&k("1.5.2")){var f=!1,g={};g.url=a;g.type="GET";g.data=b;g.cache=!1;g.dataType="text";e&&(g.xhrFields={withCredentials:!0});null!=c&&(g.success=c);jQuery.ajax(g)}f&&(null!=c&&(e=("r"+h()).replace(".",""),b.cbfnc=e,window[e]=c),b._=h(),c=document.createElement("SCRIPT"),c.src=a+d(b),c.type="text/javascript",(document.head||document.getElementsByTagName("head")[0]).appendChild(c))},
U:function(){return window.location!=window.parent.location?document.referrer:document.location}}},{}],7:[function(q){var g=q("./lib/config-measuring"),d=q("./lib/detection")(g),k=q("./lib/reporting")(g);d.H(!0,function(d,g,f){k.G(d,g,f);"undefined"!==typeof pf_notify&&jQuery.isFunction(pf_notify)&&pf_notify(d,g)})},{"./lib/config-measuring":2,"./lib/detection":4,"./lib/reporting":5}]},{},[7]);