// houyuan.c ��Ժ
//lpg 19991005

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ������������������һ��Բ�ε��Ŷ�����һ��С·ͨ��
��ɽ��
LONG );
        set("exits", ([
                "north" : __DIR__"sanqingdian",
        ]));
        setup();
        replace_program(ROOM);
}
