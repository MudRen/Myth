//Cracked by Roath

inherit ROOM;

void create ()
{
        set ("short", "��Բ��");
        set ("long", @LONG

    �ս��������һ�ۿ����ľ����Ǻպ����������ƣ�
[35m
                ������������������
                ��   �����Բ   ��
                ������������������
[m
Ҳ��������Ͳ������ڵ������Բ���������ϰ����̬��
�ã��ټ������ǵ���Բζ��Ҳ�������Ҳ��ϰ���ˡ�

LONG);

        set("exits",
        ([ //sizeof() == 4
                "south": __DIR__"sibei-w1",
      ]));
      set("objects", ([
                                __DIR__"npc/ling" :1,
                ]));

      set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
