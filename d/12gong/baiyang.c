// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "��һ��������");
        set ("long", @LONG
Ф�������ǳ����ߣ�ֻҪһ��˯�߳���㾫�����棬��֮��˯�߲�����ٲ�������
��Ф������������ѱ�����������Ҫ�г����˯�ߡ�Ф�����������������˯һ�߲��ط���
���������Ф��������˯������һ�����ᷭ��Ф�������ĸ���̹�ס�ֱ�ʲ���������
�����л�ϲ��ֱ�ӽ�������


LONG);


        set("exits", ([
        "northup"    :       __DIR__"by2jn1",
            "eastdown"  :       __DIR__"toby2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baiyang" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if ( present("xiaoshu jun") && dir == "northup" )
        return notify_fail("Ф��������Цһ�����ȹ��������˵��\n");
        return ::valid_leave(me, dir);
}

void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
