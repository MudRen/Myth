// ������ by Calvin

inherit ROOM;

void create ()
{
        set ("short", "ϡ��С��");
        set ("long", @LONG

����һ�Ҳ����ĵ���,�����ﾭӪ�����������Χ��ǧ��ٹֵĸ�����Ʒ��
������������򵽼��������㺱���ĵĶ���,��������ļ۸�Ҳ�Ǳ���һ��

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "east": "/d/calvin/lanling/jie4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
            "/d/wizz/cigar/npc/cuier" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
