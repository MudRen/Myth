// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ��");
  set ("long", @LONG

��������˾����ɽ�£���ΧһƬ������������ľ��һƬ�ž���
ֻ����������ع��š�ɽ���µ��������棬��˵�е���˾ʮ
�˲�������������û���˴�������ų�ȥ��


LONG);


  setup();
}
void init()
{
	add_action("do_get","eat");
	add_action("do_get","get");
        add_action("do_get","kill");
        add_action("do_get","fight");
        add_action("do_get","cast");
        add_action("do_get","bian");
        add_action("do_get","fly");
        add_action("do_get","look");
        add_action("do_get","l");
        add_action("do_get","perform");
        add_action("do_get","steal");
	
}
int do_get(string arg)
{
	return 1;
}
