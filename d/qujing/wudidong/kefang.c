// kefang.c
inherit ROOM;
void create()
{
        set("short", "�ͷ�");
        set("long", @LONG

    ����ɸɾ����ģ���������Ϣ��һ�����󴲣��Ѿ���ĥ�÷���
�ˡ��ݽ�����Ÿ�¯�ӣ��Ա�����ȡů��

LONG
        );

        set("sleep_room",1);
        set("if_bed",1);
        set("exits", ([
                "north" : __DIR__"shop",
	]));
        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}
