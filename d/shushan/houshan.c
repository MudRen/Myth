//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
        һ��С·ͨ����ɽ���ء�
LONG
        );

        set("exits", ([
                "north" : __DIR__"bamboo",
                "southwest" : __DIR__"houdian",
                "eastup" : __DIR__"feipu",
        ]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{

   if (dir == "north" ) {
        if (me->query("family/family_name") == "��ɽ����")
        {
        if (me->query("shushan/ask_zuidao_go"))
        return ::valid_leave(me, dir);
        return notify_fail("���Ȼ������ʥ�Ļ��������ɽ��أ����±��ط��𣡣���\n");
        }
        if (objectp(present("jian tong", environment(me))))
   return notify_fail("��ɽ��ͯ������˵������ɽ�˱��ɽ��أ�������ذɣ���\n");
        }   
        return ::valid_leave(me, dir);
}

