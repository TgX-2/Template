# Template

<style>
    .markdown-body { 
        max-width: 2048px; 
    }
    
    var md = require('markdown-it')().use(require('markdown-it-abbr'), abbrDefList, true);
    md.render(/*...*/); 

    details summary {
        display: block;
        cursor: pointer;
        background-color: coral;
    }
    details strong::after {
        color: red;
        content: " [Collapsed]";
        font-family: "Fantasy";
    }
    
    details[open] strong::after {
        color: purple;
        content: " [Expanded]";
        font-family: "Fantasy";
    }
    
    details[open] pre {
        filter: blur(4px);
        -webkit-transition : -webkit-filter 27204ms linear
    }
    
    details[open] p {
        filter: blur(4px);
        -webkit-transition : -webkit-filter 27204ms linear
    }
    
    details[open] blockquote * {
        filter: blur(0px);
    }
    
    details[open] blockquote *::after {
        content: "";
    }
    
    details[open] :hover {
        filter: blur(0px);
        -webkit-transition : -webkit-filter 250ms linear
    }
    
    details[open] :after {
        filter: blur(0px);
    }
    
    
    .spoiler * { 
        transition: color 0.5s; 
        position: relative;
    }
     
    .spoiler::after {
        content: 'Hidden Content';
        position: absolute;
        top: 0; left: 0;
        color: transparent;
    }
    
    .spoiler:not(:hover) * { color: transparent; }
    .spoiler:not(:hover)::after { transition: color 0.3s 0.3s; }
    
    details.spoiler summary::after {
      content: var(--hidden);
      filter: blur(4px);
      display: block;
    }

    details[open] summary::after {
      display: none;
    }
</style>

:::info
> 🔗 Link  : []() 
> ✍🏻 Tác giả: Bùi Đình Lộc - 11Ti - THPT Chuyên Hùng Vương (Bình Dương)
> 📋 Nội dung:
> [TOC] 
> 
> [color=blue]
:::


___

# Bài 1. 

## 1.1. Tóm tắt đề bài

## 1.2. Lời giải

### ***Subtask 1:***
***Ý tưởng:***

***Code:***
:::info

Độ phức tạp : $O(n)$

:::spoiler {class="spoiler" state="close"}
```cpp=

```
:::



### ***Subtask 2:***
***Ý tưởng:***


***Code:***
:::info

Độ phức tạp : $O(n)$

:::spoiler {class="spoiler" state="close"}
```cpp=

```
:::
