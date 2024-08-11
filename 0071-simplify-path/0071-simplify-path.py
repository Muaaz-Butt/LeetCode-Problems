class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        components = path.split('/')

        for component in components:
            if component == '.' or component == "":
                continue
            if component == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(component)
        return '/' + '/'.join(stack)