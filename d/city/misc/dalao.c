//Cracked by Roath
// Room: /city/jianyu.c
#include <ansi.h>
inherit ROOM;
void init();
void create()
{
    set("short", "��������");
    set("long", @long

������һ���������η���ר��������Ѻ���鷸��֮ͽ�������г��
��һ�ɸ������߸ߵ�����͸��һ˿���⣬��ֻ�������������µ�����
��ߴ�����ȥ�����������������Ϊ�����������֡�
long
    );
    set("valid_startroom", 1);
    set("no_fight", 1);
    set("no_move", 1);
    set("objects", ([
        "/d/obj/food/jitui" : 3,
        "/d/moon/obj/jiudai" : 1,
    ]));
    setup();
}
void init()
{
    object ob;
    ob = this_player();
      ob->set("startroom","/d/city/misc/dalao");
        remove_call_out("kick_ob");
    call_out("kick_ob",30);
}
void kick_ob()
{
    object room,*obj;
        int i;
        
        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("summon_time"))>300){
                        message_vision(HIR+"�ѵ�һ����һ����������ţ�����������׳԰׺ȣ�˵��һ�Ű�$N�ߵ��˾������⣡\n"+NOR,obj[i]);
                if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        obj->start_busy(10);
                        message("vision",HIY+"�������ƹ�����������һ���ҽУ�һ���һﱻ��������!\n"+NOR,room,({obj[i]}));
                obj[i]->set("kee",-1);
                        tell_object(obj[i],"���۵Ĳ����˹�ȥ...\n");
            obj[i]->set("startroom","/d/city/kezhan");
                    call_out("kick_ob",30);
                        return;
                }
        }
    call_out("kick_ob",100);
}
