inherit ROOM;

void create()
{
        set("short", "�߻�͡");
        set("long", @LONG
����¥����֮����������Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ����ʤ��
�ǻ�����Ѱ����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ����ֵ��ǧ��
�ǻ����������Ŷ��棬��Χ�Ժ�ʯ��֮���仨���絤�̣���ɫ���ã��⻪
��Ŀ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"jiyuan2",
        ]));

        setup();
        replace_program(ROOM);
}

