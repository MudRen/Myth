inherit ROOM;

void create()
{
        set("short", "���յ�");
        set("long", @LONG
վ�����մ���ϣ���ᷢ���������п�����֮�֣��ֵ�������ֲ�ɰأ�
�������ŵƽ�ʡ�������������������̡��ٽֵ����ﾭӪ�����塢��
�����մɡ��Ŷ������ơ�С�Եȣ����ַǷ���������������ڣ��ǳ�����
�֣���ɽ�˺����������У�����������ҵ�������Ҫ�Ķ������ϱ���һ��
��֬�꣬�в�������Ů��ǰ����ˡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"eroad5",
                "north" : __DIR__"miaohui",
                "south" : __DIR__"jinyin",
                "west" : __DIR__"eroad3",
        ]));

        setup();
        replace_program(ROOM);
}

