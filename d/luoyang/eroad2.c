inherit ROOM;

void create()
{
        set("short", "���յ�");
        set("long", @LONG
վ�����մ���ϣ���ᷢ���������п�����֮�֣��ֵ�������ֲ�ɰأ�
�������ŵƽ�ʡ�������������������̡��ٽֵ����ﾭӪ�����塢��
�����մɡ��Ŷ������ơ�С�Եȣ����ַǷ���������һ��˽�ӣ��ϱ�����
�˵޽��Լ�ͽ����Լ�ĵط�����һ��ǣ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"eroad3",
                "north" : __DIR__"sishu",
                "south" : __DIR__"yuelao",
                "west" : __DIR__"eroad1",
        ]));
        setup();
        replace_program(ROOM);
}

