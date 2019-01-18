#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������һ��");
  set ("long", @LONG

����к���ͻأ��գ�������ɫ��������������������ƣ��г�
�޻𣬲�����ǰ����������ڸ�ɳ档����������ϣ����̾�����
�����⣬����ǰ������ǣ�ɡ�
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/kusu" : 1,
//]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower2",
]));

  setup();
}
void init()
{
  add_action("do_shao", "shao");
  add_action("do_knock", "knock");
  add_action("do_knock", "qiao");
}
int do_shao(string arg)
{
	object me=this_player();
	
	if(!arg && arg != "di" && arg!="floor")
		return notify_fail("��Ҫɨʲô��\n");

	if(!present("broom", me))
		return notify_fail("ûɨ�صļһ���ô�У�\n");

	if(query("clean"))
		return notify_fail("���¹��ɾ��ˣ�����ɨ�ˣ�\n");

	if((int)me->query("kee") <50)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	message_vision("$N�����Ŵ�ɨ��ɨ������������Ƭ�Ļҳ���\n", me);
	write("�ҳ�ɢ�������ڵ��������Ǵ�����ˡ�\n");
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц��\n", me);
	me->receive_damage("kee", 30);
	me->add_temp("clean_floor", 1);
	
	if((int)me->query_temp("clean_floor") > 13){
		me->delete_temp("clean_floor");
	}
	set("clean", 1);
	call_out("regenerate", 800);
	set("long", @LONG

����к���ͻأ��գ�������ɫ����������ת�紩�ߣ��ſ��Ƴ�
������ƿӰ������£������������Ϸ硣���������ܹ���������
����������ʯ�������͸�����������Զ������ǧ���⣬�ߵ�
���ھ����С�
LONG);

	return 1;
}
int regenerate()
{
  set ("long", @LONG
                
����к���ͻأ��գ�������ɫ��������������������ƣ��г�
�޻𣬲�����ǰ����������ڸ�ɳ档����������ϣ����̾�����
�����⣬����ǰ������ǣ�ɡ�
LONG);  

        set("clean", 0);
        return 1;
}


int do_knock(string arg)
{
        object me;

        me=this_player();

        if( !arg || (arg != "men" && arg != "door" && arg != "��" ) )
                return notify_fail("��Ҫ��ʲô��\n");       
        call_out("open_up", 1);
        return 1; 
}

void open_up()
{
        object uproom; 

        if( !(uproom = find_object(__DIR__"baodian")) )
                uproom = load_object(__DIR__"baodian");

        if( uproom = find_object(__DIR__"baodian") ) 
        {
                set("exits/out", __DIR__"baodian");
                uproom->set("exits/enter", __FILE__);
		message("vision", "С�ű��˴��ˡ�\n", uproom);
		message("vision", "С�ű��˴��ˡ�\n", this_object());
        }

        call_out("close_up", 100);
}

void close_up()
{
        object uproom;

        if( !query("exits/out") ) return;
	message("vision", "С�ű��˹����ˡ�\n", this_object());


        if( uproom = find_object(__DIR__"baodian") ) 
        {
		message("vision", "С�ű��˹����ˡ�\n", uproom);
                uproom->delete("exits/enter");
        }

        delete("exits/out");
}


