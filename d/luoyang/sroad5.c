inherit ROOM;

void create()
{
        set("short", "���Ƶ�");
        set("long", @LONG
���ƴ��λ��������������棬����������ضΣ���ʯ���̳ɵĽ�
�棬���������࣬һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц������������
�������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ����
��һ�����ߵ������ͻȻ�е�һ��ǿ�ҵ���֬����ζ�Ӷ��洫����ԭ��
�������������¥-����¥��������һ������̣����쵽�����������
��ͣ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"jiyuan",
                "south" : __DIR__"sroad6",
                "west" : __DIR__"datie",
                "north" : __DIR__"sroad4",
        ]));
        set("objects", ([
                "/d/luoyang/npc/piaoke" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

