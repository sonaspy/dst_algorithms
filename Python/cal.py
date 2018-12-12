expression = input()

def middle2behind(expresssion):  
    result = []             
    stack = []              
    for item in expression: 
        if item.isnumeric():      
            result.append(item) 
        else:                     
            if len(stack) == 0:   
                stack.append(item)
            elif item in '*/(':   
                stack.append(item)
            elif item == ')':     
                t = stack.pop()
                while t != '(':   
                    result.append(t)
                    t = stack.pop()
            
            elif item in '+-' and stack[len(stack)-1] in '*/':
                if stack.count('(') == 0:           
                    while stack:
                        result.append(stack.pop())
                else:                               
                    t = stack.pop()
                    while t != '(':
                        result.append(t)
                        t = stack.pop()
                    stack.append('(')
                stack.append(item)  
            else:
                stack.append(item)

    
    while stack:
        result.append(stack.pop())
    
    return " ".join(result)


print(middle2behind(expression))