
inherit ROOM;

void create ()
{
        set ("short", "��ҩ����");
        set ("long", @LONG

���ǽ��ݳ�������һ����ҩ����,�����漸�������˸����ݿ�����
����ɽ����������ҩ�������ϼ������ֲӽ�������ʱ���������
����ģ������ϰ��֮�˽�����ҩ��
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "south": __DIR__"pingan-1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

