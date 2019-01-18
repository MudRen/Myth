#include <ansi.h>
#include <room.h>

inherit MAGIC_ROOM;    //ע����MAGIC_ROOM ��ROOM     
string *list=({"yg-moon1","yg-moon2","yg-fangcun","yg-longgong","yg-jjf1","yg-jjf2","yg-hyd1","yg-hyd2","yg-hell","yg-gumu1","yg-gumu2",
        "yg-pansi","yg-putuo","yg-sanjie1","yg-sanjie2","yg-shushan","yg-wdd2","yg-wzg1","yg-wzg2","yg-xueshan",
        });

void create (int level,int num)
{
        object obj,wang; 
        int i,value; 
        set ("short", HIB "�����Ų�" NOR); 
        set ("long", @LONG
����������������ɭ�ֲ����洦�ɼ���ɫ�Ĺ��һ��һ����
�ڰ�����Լ��һ��ǽ�����ڲ�ͬ������һ��ʯ��(door)��
LONG);
        level=50;num=random(3)+4;  
//level �ǹֵļ���10-30, num �ǹֵ���Ŀ
        set("exits", ([ 
        "enter" : __DIR__"baoku19", 
//                "west" : __DIR__"dong",
                 ]));
        set("level",level);//�Լ������趨��
// �����Ժ�ֵĵĵȼ�
        set("alternative_die",1); 
        set("magicroom",1); 
//���������־��cmds npc �ж����裡
        set("npc_num",num);//�Լ������趨��
        set_heart_beat(240);
// �����Ժ�ֵ���Ŀ
        set("objects",([                       
                __DIR__"npc/yg-shushan" : 1,
                __DIR__"npc/yg-sanjie2" : 1, 
                __DIR__"npc/yg-moon2" : 1,    
                __DIR__"npc/yg-hell" : 1,       
                __DIR__"npc/yg-xueshan" : 1,          
                __DIR__"npc/yg-longgong" : 1,    
        ]));
//        create_door("west", "ʯ��", "east", DOOR_CLOSED);         
        setup();
        setup2();
// setup2();������   
}

void init2()
{    
}

/* �����Ǹ���ʱ�䡢 ���ݵ��趨*/
void reset()
{
        object guai;
        int i,level,value;
 
        this_object()->add_temp("npc_times",1);
        if (this_object()->query_temp("npc_times")>10){
                this_object()->set_temp("npc_times",1);
                if(this_object()->qurey("npc_num")> 0){
                        for(i=0;this_object()->query("npc_num");i++) { 
                                guai = new("/d/quest/yaota/npc/"+list[random(sizeof(list))]);
                                level=this_object()->query("level");
                                guai->set("level",level);
                                guai->create(value,level);
                                guai->set_skills(level);
                                guai->move(this_object());
                        }
                }
        }
        ::reset();
}

int valid_leave (object who, string dir) 
{ 
        object where = this_object (); 
        object obj = present ("moguai",where);
        if (obj) 
        return notify_fail ( obj->name()+"˵������������ͱ����ȥ�����ٺ�...\n"); 

        return ::valid_leave (who, dir); 
} 
