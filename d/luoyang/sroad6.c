inherit ROOM;

void create()
{
        set("short", "���Ƶ�");
        set("long", @LONG
���ƴ��λ��������������棬����������ضΣ���ʯ���̳ɵĽ�
�棬���������࣬һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц������������
�������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ����
��һ����������һ�����ε꣬��������˽����鱦�����ߵ�ˮ���꣬����
������ˮ����Ӧ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"shoushi",
                "south" : __DIR__"sroad7",
                "west" : __DIR__"shuiguo",
                "north" : __DIR__"sroad5",
        ]));

        setup();
        replace_program(ROOM);
}

