// created by angell 1/1/2001
// room: /d/qujing/huangfeng/yaopu.c

inherit ROOM;

void create ()
{
        set ("short", "����ҩ��");
        set ("long", @LONG

����������Ũ�ص�ҩ�����ϰ���б���ڳ����ϴ�������
ҩ�Ķ��Ǵ����ɽ�ϲ����ġ���˵��һ��λҩ�ļ�Ϊ�ѵã�
����ҩ���ϰ����ϴ��µļ���������Ч��ҩ����С��������
��һʱ������ɽ���л���ҩ�������������ˣ�����Ҳ���嵭
����ࡣ

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 1
                "north" : __DIR__"tulu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yaoboss" : 1,
                "/d/obj/misc/tables" : 1,
        ]));


	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
