inherit ROOM;

void create()
{
        set("short", "���յ�");
        set("long", @LONG
վ�����մ���ϣ���ᷢ���������п�����֮�֣��ֵ�������ֲ�ɰأ�
�������ŵƽ�ʡ�������������������̡��ٽֵ����ﾭӪ�����塢��
�����մɡ��Ŷ������ơ�С�Եȣ��������ַǷ������������������Ĺ㳡
�ˣ��ϱ����߷ֱ���������Ϳ��׵꣬ͬ��һ���ϰ�������
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"eroad2",
                "north" : __DIR__"armor",
                "south" : __DIR__"weapon",
                "west" : __DIR__"center",
        ]));
        set("objects", ([
                "/d/luoyang/npc/maiyi1" : 1,
                "/d/city/npc/boy" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

