inherit ROOM;

void create()
{
        set("short", "���ϴ�ϷԺ");
        set("long", @LONG
ϷԺ����һ���߸ߵ�Ϸ̨��̨��һЩ�����Ϲ�ױ���ˣ�����Ϸ������
�ŵ��ߣ��������㵸������ѽѽ�ĳ����й��Ĺ��⾩�磬̨���кü�����
�ӣ�������Ϸ�ԣ�Ʊ�ѣ������²����Ŀ���̨�ϵı��ݣ������������
��סվ���������һ�����á���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtai",
                "west" : __DIR__"sroad4",
        ]));
        set("objects", ([
                "/d/luoyang/npc/guanzhong" : 4,
                "/d/qujing/chechi/npc/xizi" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

