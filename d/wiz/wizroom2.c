//��ʦ������
//by Calvin

inherit ROOM;

void create ()
{
        set ("short", "��ʦ������");
        set ("long", @LONG

�� ������Ե���ɽ��ܡ�- Ŀǰ����
1.�Ϻ�����ɽ 2.����ɽ��˿��  3.����ɽ�¹� 4.��̨����ɽ 5.���ܵظ� 
6. �������� 7.���ɽ����ƶ� 8.�ݿ�ɽ�޵׶� 9.����ɽ��һ�� 10.����ɽ
��ׯ�� 11.��ѩɽ���޹� 12.���ƽ����� 13.��֮����ɽ 14.���(������)

LONG);

        set("exits", 
        ([ //sizeof() == 4
      "up" : __DIR__"wizroom",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
