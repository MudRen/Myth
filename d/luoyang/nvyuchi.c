inherit ROOM;

void create()
{
        set("short", "Ůԡ��");
        set("long", @LONG
�����������ڣ��������ƣ�һ�ж�������֮�У��޷��������У�΢��
���ԣ�����������������۾���ϸһ��������������������������Ů��
���Ƕ�Ү���ٿ����Լ����������μ�穡��������������ǸϿ��Ҹ��ط�ϴ
��ɣ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"rest2",
        ]));

        setup();
        replace_program(ROOM);
}

