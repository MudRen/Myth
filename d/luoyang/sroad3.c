inherit ROOM;

void create()
{
        set("short", "���Ƶ�");
        set("long", @LONG
���ƴ��λ��������������棬����������ضΣ���ʯ���̳ɵĽ�
�棬���������࣬һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц������������
�������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ����
��һ������������Ǯ�����ܵĵط�-���ԡ�أ����������Ƕ�ͽ�ǵ�����-
���ַ���
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"yuchi",
                "south" : __DIR__"sroad4",
                "north" : __DIR__"sroad2",
                "west" : __DIR__"duchang",
        ]));

        setup();
        replace_program(ROOM);
}

