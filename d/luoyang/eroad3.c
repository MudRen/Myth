inherit ROOM;

void create()
{
        set("short", "���յ�");
        set("long", @LONG
վ�����մ���ϣ���ᷢ���������п�����֮�֣��ֵ�������ֲ�ɰأ�
�������ŵƽ�ʡ�������������������̡��ٽֵ����ﾭӪ�����塢��
�����մɡ��Ŷ������ơ�С�Եȣ����ַǷ���������һ�Ҵ����꣬�ϱ���
һ�������տ����ӵĵط�������Ӥ�á�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"eroad4",
                "north" : __DIR__"ciqi",
                "south" : __DIR__"yuying",
                "west" : __DIR__"eroad2",
        ]));
        set("objects", ([
                "/d/luoyang/npc/xianren" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

