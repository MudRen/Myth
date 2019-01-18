// mcheck.c
// Created by bbb@SJ
/*
   Modified by snowman@SJ 28/06/2000
   added ip check and player check.
   also added passwd & email check.
*/


#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, j, count = 0;
        object *lob, obj, *obs;
        string ip, tmp, str = HIR"\n  ���� �����ص�¼(ML) ���� "NOR;
	mixed groups;
     	int ip1,ip2,ip3,ip4,n,myip,yourip;
    	string arg1;
	
	obs = filter_array(objects(), (: interactive :));
        obs = filter_array(obs, (:environment:));
        obs = sort_array(obs, (:strcmp(query_ip_number($2), query_ip_number($1)):));
        i = sizeof(obs);
        
	if( stringp(arg) ){
		if( objectp(obj = LOGIN_D->find_body(arg)) && me->visible(obj) && interactive(obj)){
			arg = query_ip_number(obj);
			tmp = "\n"+ obj->name(1) +"("+ obj->query("id") +")\nIP��"+ arg +"\nPort��["+query_ip_port(obj)+"]\n";
			tmp += "Ŀǰ�ʹ��˴���ͬIP���������У�\n\t";
		}
		else tmp = "\nĿǰͨ�� " + arg + " ���������У�\n\t";
 		n=sscanf(arg,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
		myip = (ip1<<24)+(ip2<<16)+(ip3<<8)+ip4;
		while(i--){
			if( obs[i] == obj ) continue;
        		arg1 = query_ip_number(obs[i]);
			sscanf(arg1,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
			yourip = (ip1<<24)+(ip2<<16)+(ip3<<8)+ip4;
        		if (query_ip_number(obs[i]) == arg
			|| (myip>>(8*(4-n)))==(yourip>>(8*(4-n)))){
				tmp += sprintf("%-25s ", obs[i]->query("name") + "("+obs[i]->query("id")+")" + "["+query_ip_port(obs[i])+"]");
				count++;
				if( count % 3 == 0 ){
					tmp += "\n\t";
					count = 0;
				}
			}
		}
		write(tmp+"\n");
		return 1;
	}
	
	groups = unique_array(obs, (: query_ip_number($1) :));
	if ( !sizeof(groups) ) return notify_fail(HIR"\n  ���� ��� ���� \n"NOR);
	
	for(i = 0; i < sizeof(groups); i++) {
		if( sizeof( groups[i])  <= 1)  
			continue;
		obs = groups[i];
		lob = obs->query_temp("link_ob") - ({0});
		ip = query_ip_number(obs[0]);
		tmp = sprintf("\n"HIY"%-16s"WHT" �� "NOR, ip);
		for( j = 0; j < sizeof(obs); j++ ){
			if( j > 0 && j % 4 == 0 ) tmp += "\n\t\t    ";
			tmp += sprintf("%-16s", obs[j]->query("id")+"("+ query_ip_port(obs[j])+")");
		}
		
		str += tmp;
		lob = sort_array(lob, (:strcmp($1->query("password"), $2->query("password")):));
	        count = sizeof(lob);
	        ip = j = 0;
	        tmp = arg = "";
	        while(count--){
	        	if (lob[count]->query("password") != ip) {
	                	if (j > 1) arg += "(" +tmp+") ";
	                        ip = lob[count]->query("password");
	                        j = 0;
	                        tmp = "";
	                }
	                tmp += lob[count]->query("id")+", ";
	                j++;
	        }
	 	if (j > 1) arg += "(" +tmp+") ";
	        if( arg != "" ) str += HIG"\n\t\t    ������ͬ���У�"+arg+NOR;
	        lob = sort_array(lob, (:strcmp($1->query("email"), $2->query("email")):));
	        count = sizeof(lob);
	        ip = j = 0;
	        tmp = arg = "";
	        while(count--){
	                if (lob[count]->query("email") != ip) {
	                        if (j > 1) arg += "(" +tmp+") ";
	                        ip = lob[count]->query("email");
	                        j = 0;
	                        tmp = "";
	                }
	                tmp += lob[count]->query("id")+", ";
	                j++;
	        }
	        if (j > 1) arg += "(" +tmp+") ";
	        if( arg != "" ) str += HIC"\n\t\t    Email��ͬ���У�"+arg+NOR;
	}

        str += HIR"\n  ���� ��� ���� \n"NOR;
        me->start_more(str);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��mcheck [ip|ĳ��]

����
	mcheck 61.137.155.126   -> �г��Ӵ�ip�������ҡ�
	mcheck 61.137.   	-> �г��Ӵ�ip��Χ���������ҡ�
	mcheck snowman		-> �г��ʹ������ͬip��������ҡ�
	mcheck			-> �г�������ͬip���б�������ͬ email�� passwd�б�
	
HELP
        );
        return 1;
}



