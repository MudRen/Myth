//Cracked by Roath
// go.c
#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;
#define DIR_NAME   0
#define DIR_XX     1
#define DIR_YY     2

mapping default_dirs = ([
        "north":                ({"��", 0, 1,}),
        "south":                ({"��", 0,-1,}),
        "east":                 ({"��", 1, 0,}),
        "west":                 ({"��",-1, 0,}),
        
        "northeast":    ({"����", 1, 1,}),
        "northwest":    ({"����",-1, 1,}),
        "southeast":    ({"����", 1,-1,}),
        "southwest":    ({"����",-1,-1,}),
]);

void create() { seteuid(getuid()); }

// follow will have silent=2, so as to reduce the CPU load.
int main(object me, string arg)
{

        object env;
        mapping position;
        int pos,xx,yy;
        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n");
        if(!env->query("hellfireroom"))
                 return notify_fail("�˴������巽λ��\n");
        if( !arg ) return notify_fail("��Ҫ���ĸ���λ�����ߣ�\n");
        
        if(!me->query_temp("position"))
            {
                if(userp(me))
                  me->set_temp("position",(["xx":18+random(5),"yy":18+random(5),"zz":0,]));
                  else me->set_temp("position",(["xx":18+random(5),"yy":18+random(5),"zz":random(3),]));
             }
             position=me->query_temp("position");
        
         if (arg=="up" && (!userp(me) || wizardp(me))) 
                  {
                   if( position["zz"]+1 >=3) return 1;
                       position["zz"] +=1;
                       me->set_temp("positiom",position);
                       return 1;
                  }
                  else if (arg=="down" && (!userp(me) || wizardp(me)))
                   {
                   if( position["zz"]-1 < 0) return 1;
                       position["zz"] -=1;
                       me->set_temp("positiom",position);
                       return 1;
                   }
        if(undefinedp(default_dirs[arg]))
                 return notify_fail("��Ҫ���ĸ���λ������һ����\n");
        
        if( env->query("position_max") && (env->query("position_max") > 2 && env->query("position_max") < 8))
                pos=env->query("position_max");
                else pos=3;
                
        if((xx=position["xx"]+default_dirs[arg][DIR_XX]) <= (20-pos) || xx >= (20+pos) )
                return notify_fail("�˵�һ�����������ײ��ʲô��\n");
        if((yy=position["yy"]+default_dirs[arg][DIR_YY]) <= (20-pos) || yy >= (20+pos) )
                return notify_fail("���˵��������������ײ��ʲô��\n");
                
                position["xx"]=xx;
                position["yy"]=yy;
                me->set_temp("position",position);
             tell_object(me,"�㳯"+default_dirs[arg][DIR_NAME]+"��λ����һ����\n");
            return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : gogogo <����>
 
������ָ���ķ�λ�����ƶ�������˸�����λ�ƶ�һ����
 
HELP
    );
    return 1;
}

