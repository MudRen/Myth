#include <ansi.h>
#include <room.h>

inherit MAGIC_ROOM;    //ע����MAGIC_ROOM ��ROOM     
string *list=({
        "yg-moon1","yg-moon2","yg-fangcun","yg-longgong","yg-jjf1","yg-jjf2","yg-hyd1","yg-hyd2","yg-hell","yg-gumu1","yg-gumu2","yg-sanjie1","yg-sanjie2","yg-wzg1","yg-wzg2","yg-wdd2","yg-putuo","yg-pansi","yg-shushan","yg-xueshan",
});

void create (int level,int num)
{
        object obj,wang; 
        int i,value; 
        set ("short", HIB "�����˲�" NOR);
        set ("long", @LONG
����������������ɭ�ֲ����洦�ɼ���ɫ�Ĺ��һ��һ����
LONG);
        level=45;num=random(2)+4;
//level �ǹֵļ���10-30, num �ǹֵ���Ŀ
        set("exits", ([ 
                "up" : __DIR__"tower9",
                "east" : __DIR__"baoku16",
                "west" : __DIR__"baoku18",
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
                __DIR__"npc/yg-putuo" : 1,
                __DIR__"npc/yg-sanjie1" : 1, 
                __DIR__"npc/yg-gumu2" : 1,    
                __DIR__"npc/yg-wzg2" : 1,       
                __DIR__"npc/yg-jjf1" : 1,       
        ]));
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
        object guai,wang;
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
