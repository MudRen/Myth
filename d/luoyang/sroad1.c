inherit ROOM;

void create()
{
        set("short", "���Ƶ�");
        set("long", @LONG
���ƴ��λ��������������棬����������ضΣ���ʯ���̳ɵĽ�
�棬���������࣬һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц������������
�������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ����
��һ����������һ�����ֵ��������Ĺ㳡��������һ�ҿ�ջ����Ի������
��ջ�����������Ƿ�Բǧ��֮������һ�ҵ��̡�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"kezhan",
                "south" : __DIR__"sroad2",
                "north" : __DIR__"center",
                "west" : __DIR__"dangpu",
        ]));

        setup();
        replace_program(ROOM);
}

