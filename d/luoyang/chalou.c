inherit ROOM;

void create()
{
        set("short", "���ǲ�¥");
        set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����
һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹ�
��ҥ�ԣ������Ǹ������ڡ���������Ϣ�ң���¥�Ͽ�������˵�顣
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sroad2",
                "up" : __DIR__"chalou2",
                "west" : __DIR__"rest",
        ]));
        set("objects", ([
                "/obj/boss/luoyang_teahuoji" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

