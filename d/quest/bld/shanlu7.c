//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ·");
        set ("long", @LONG

һ���������۵�С·������ֻͨ��ɽ�ϣ�������·���ͣ���̫��
�ߡ������ǵ��Ұ��������С�ݡ�
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southdown" : __DIR__"shanlu6",
                "northup" : __DIR__"shandian",
        ]));

        set("item_desc", ([ /* sizeof() == 1 */
                "northup" : "������Լ����ɽ�ߡ�\n",
]));

        set("objects", 
        ([ //sizeof() == 2
               __DIR__"npc/erlang" : 1,
               __DIR__"npc/dog" : 1,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
   if (dir == "northup" ) {
        if (objectp(present("erlang shen", environment(me))))
   return notify_fail(HIW"������"NOR+"˵����������������ʥĸ֮�أ��������뿪��"
+HIW"Х��Ȯ"NOR+"������˼�����\n\n",me);

        }   
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_dian", "dian");
}

int do_dian(string arg)
{       
        object me=this_player();
        object deng;
        object erlang=present("erlang shen", this_object());
        object dog=present("xiaotian quan", this_object());

        if(!(deng=present("baolian deng", me)))
        return notify_fail("��û"+HIY"������"NOR+"��ô�㣿 \n");

        if (arg != "deng"  && arg!= "baolian deng")
        return notify_fail("��Ҫ��ʲô�� \n");

        if ( me->query("bld/done") ==1)
        return notify_fail("�㵱����Ԫ���ڣ�û�µ���棿 \n");

        if (me->query("bld/erlang") != 1  || me->query("bld/dog") !=1)
        return notify_fail("���Ƶ�ʱ�仹���أ� \n");

       message_vision(HIY"������"NOR+"������ĵ�ȼ���ų������â�� \n",me);
       destruct (erlang);
       destruct(dog);
       destruct(deng);
       message_vision(HIW"Х��Ȯ"NOR+"��"HIW"������"NOR+"һ�±����ճ��˻ҽ�����ɢ��ȥ�� \n",me);
       message_vision(HIY"������"NOR+"Ҳ������������绯ȥ�� \n",me);
       return 1;
}

