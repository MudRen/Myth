//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ��");
        set ("long", @LONG

��ɽ���ڲ�����ʥĸ�ͱ�Ѻ��������������ʮ�����ˡ���
����һ����̨�������Ѻ��ʥĸ����̨�ϻ���һ�������ֻҪ
�ң�jie��������ʥĸ�������ˣ�
LONG);

        set("exits", 
        ([ //sizeof() == 0
        
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jie", "jie");
}

int do_jie(string arg)
{
         object where = this_object();
         object me=this_player();
         object *ob = all_inventory(environment(me));
         int i;
         object shengmu=present("san shengmu",where); 

         if (arg!= "fu")
         return notify_fail("��Ҫ��ʲô�� \n");
         if (shengmu)
         return notify_fail(HIM"��ʥĸ"NOR+"�������� \n");

         if (me->query("bld/done") > 0)
         return notify_fail("�㲻�ǽҹ����� \n");

         if (me->query("bld/dog")!= 1 || me->query("bld/erlang")!=1 
             || me->query("bld/pi")!=1 ) {
         
         return notify_fail("û�˽���ң����ҽ�ʲô���������ȥ�� \n");
           return 1;                     }

            if (sizeof(ob)>1)
         return notify_fail("���ﶫ��̫������"+HIM"��ʥĸ"NOR+"�᲻���˵ģ�\n");
           
if (me->query("lucky/bld")>0){
me->add("bld/done",1);
return notify_fail("�����ѽ����ô����ɶ�� \n");}
         shengmu = new ("/d/quest/bld/npc/shengmu");
         shengmu->move(where);
         message_vision("ֻ��һ�����������"+HIM"��ʥĸ"NOR+"�ӷ�̨��Ʈ����������ֻ�������棬�����������棡 \n",me);
         me->set("bld/jie",1);
         return 1;
}
