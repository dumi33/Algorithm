
from collections import defaultdict
def solution(tickets):
    answer = []
    n = len(tickets)
    def init_graph() : 
        routes = defaultdict(list) # 디포트값이 list인 딕셔너리 
        for key, value in tickets :
            routes[key].append(value)
        return routes
    
    def dfs(key, footprint) :
        if len(footprint) == n+1 : # 다 경유한 경우 
            return footprint
        
        for idx, country in enumerate(routes[key]) :
            routes[key].pop(idx)
            
            fp = footprint[:]
            fp.append(country)
            
            ret = dfs(country, fp)
            
            if ret : return ret  # 다 경유 
            
            routes[key].insert(idx, country)
            
    routes = init_graph()
    for r in routes : # routes의 key가 r으로 
        routes[r].sort() # 경로가 2개 이상일 때 알파벳 순서가 앞서는 경로
    
    answer = dfs("ICN", ["ICN"])
    
    return answer
