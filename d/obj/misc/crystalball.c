//Rewritten by vikee for XLQY-ZQ station.
//2001-2-16 16:21
//note: I wrote it for WZG players.
// condition : 1 .family/family_name == wzg  2. daoxing > 1500 years
// virtue: the player who was founded can't know someone else is finding him.
//         so it is Wzg's players is benifit from it.

#define RUMORCENTER "/d/city/rumorcenter"
#include <ansi.h>
inherit ITEM;
object room;

void create()
{
	  set_name("ˮ����", ({"shuijing qiu","crystal","ball","qiu"}));
	  set_weight(200);
	  set("unit", "ֻ");
	  set("long", "һֻ�̹������ˮ����\n");
	  set("no_drop",1);
	  set("no_get",1);
	  set("no_give",1);
	  set("value", 10000);
	  setup();
	  room=load_object(RUMORCENTER);
	  set("room",room);
}

void init() 
{
  add_action("do_detect","detect");
  //this action is added by vikee --zhanbu
  add_action("do_zhanbu", "zhanbu");
}


int do_detect(string arg)
{
  mapping rumor;
  int number;
  object me=this_player();
  object ob=this_object();

  if (! arg || sscanf(arg, "%d", number)!=1) 
		return notify_fail("�÷���detect(1-10) \n");

  if (number<1 || number>10) 
		return notify_fail("�÷�����\n");

  if (!room) 
  {
		set("value",0);
		write("��ֻˮ�����Ѿ�ʧȥ�����ˡ�\n");    
		write("ˮ���򻯳�һ̲��ˮ����һ�ء�\n");
		destruct(this_object());
		return 1;
  }

  if (me->query("mana")<100)
		return notify_fail("��ķ����������޷���ˮ����ͨ��\n");
  
  rumor=room->reveal(number);
  set("rumor",rumor);
  me->add("mana",-10);
  message_vision(HIG"$N����ˮ���򣬿��������\n"NOR,me);
  
  if (!rumor) 
  {
		tell_object(me,"����ʲôҲû�з�����\n");
		return 1;
  }
  
  tell_object(me,CYN"�����ˮ���򣺸ղš�"+rumor["body"]+"����˭˵�ģ�\n"NOR);
  
  if (!rumor["disclose"])
	    tell_object(me,HIB"ˮ����ش��㣺�������й¶��\n"NOR);
  
  else
  {
		tell_object(me,MAG"ˮ���򻺻���ת���ţ���·���п�����һ����Ӱ��\n"); 
		tell_object(me,HIR"��ӰԽ��Խ����������ϸһ����ԭ����"HIW+rumor["name"]+HIR"("+rumor["id"]+")��\n"NOR);
  }
  return 1;
}  


int do_zhanbu(string arg)
{
        object ob, zhanbu, *ob_list;
        object me = this_player();    
        
       		if (!arg)
			return notify_fail("ָ���ʽ��zhanbu <����>\n");        
		
		if (me->query("mana")<100)
		    	return notify_fail("��ķ����������޷���ˮ����ͨ��\n");	  

		if( me->query("family/family_name")!= "��ׯ��" )
			return notify_fail("�����ׯ�۵��ӣ���ôҲŪ��������Եķ��š�\n");

		if( me->query("daoxing") < 1500000)
			return notify_fail("����л�����Ү...");



       		me->add("mana",-100);
        	message_vision(HIW"$N������ָ�������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢���ķ�λ����ϸ�������š�����\n"NOR, me);

		
		ob = find_player(arg); //just only for finding the player
		

		if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
	  		return notify_fail(CYN"����˺�������Ү...\n"NOR);
	  				
		zhanbu = environment(ob);

        	if (!zhanbu) 
			return notify_fail(CYN"����˲�֪��������Ү...\n"NOR);

                if(wizardp(ob))
			return notify_fail(CYN"ˮ������ʼ���������ɣ���ʲôҲ�����壡\n"NOR);

		tell_object(me,HIM"ˮ���򻺻���ת���ţ���·���п�����һ����Ӱ��\n"); 
        	printf(HIM"ԭ��%s(%s)��%s�Ү...��\n"NOR,(string)ob->name(),(string)ob->query("id"),(string)zhanbu->query("short"));
        
        	return 1;

}

