inherit ROOM;

void create()
{
        set("short", "���յ�");
        set("long", @LONG
��������Ҫ�����ڳ����ˣ�ԶԶ��ȥ�����Կ����سǵĹٱ����ڼ��
�Ŷӳ��ǵ�·�ˡ���Ϊ�����ʮ�ֽֿڣ����Էǳ����֡�С��С��������
����ߺ���ţ��������ǵ���Ʒ�������Ǻ�ͬ����������ǵ��ϰ���ס����
�棬�ϱ���һ���ľ�����ʯС·��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"dongdoor",
                "north" : __DIR__"hutong",
                "south" : __DIR__"suishi1",
                "west" : __DIR__"eroad4",
        ]));

        setup();
        replace_program(ROOM);
}

