inherit ROOM;

void create()
{
        set("short", "����¥����");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳�
�ȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ��
���Ŀ�������������һ�غ�ˮ���̲��������������ǳ�ɽ���룬�����ۻ룬
Ρ��׳�ۡ�
LONG);

        set("no_clean_up", 0);
        set("exits", ([
                "up" : __DIR__"zuixianlou3",
                "down" : __DIR__"zuixianlou",
        ]));
        set("objects", ([
                "/d/luoyang/npc/shike" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
