inherit ROOM;

void create()
{
        set("short", "���Ƶ�");
        set("long", @LONG
���ƴ��λ��������������棬����������ضΣ���ʯ���̳ɵĽ�
�棬���������࣬һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц������������
�������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ����
��һ���������������Ǻպ������ĺ��ǲ�¥����������һ�����ֺŵ�ҩ��
-ͬ���á�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"yaodian",
                "south" : __DIR__"sroad3",
                "north" : __DIR__"sroad1",
                "west" : __DIR__"chalou",
        ]));

        setup();
        replace_program(ROOM);
}

