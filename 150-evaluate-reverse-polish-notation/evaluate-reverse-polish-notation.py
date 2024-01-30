class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for i in tokens:
            if(i!="+" and i!="-" and i!="*" and i!="/"):
                st.append(int(i))
            else:
                t,p = st.pop(), st.pop()
                # print(t,p)
                if i=="+": st.append(t+p)
                elif i=="-": st.append(p-t)
                elif i=="*": st.append(t*p)
                elif i=="/": st.append(int(p/t))

        return st[0]