// created by snowcat 

inherit ITEM;

void create()
{
  set_name("������", ({ "diaoyu xiang", "xiang" }) );
  set_weight(250000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ�����صĵ����䡣\n");
    set("value", 2000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  add_action ("do_donate","donate");
}

int do_donate (string arg)
{
  object who = this_player ();
  object silver = present ("silver",who);
  int amount, val;
  string item;
  object obj;

  if(arg && sscanf(arg, "%d %s", amount, item)==2) {
    if( !objectp(obj = present(item, who)) )
      return notify_fail("������û������������\n");

    if(!obj->value() || obj->query("base_value")<100) 
       return notify_fail("����ֻ���ܽ�����\n");

    if( amount < 1 )
       return notify_fail(obj->name()+"������������һ����\n");
    if( amount > obj->query_amount() )
       return notify_fail("��û����ô���" + obj->name() + "��\n");
  } else {
    if (! silver)
      return notify_fail("������û�����ӡ�\n");
    obj=silver;
    amount=1;
  }

  val=obj->query("base_value")*amount/1000;
  // each gold will reduce total waiting time by 30 sec.
  // mon 4/5/98
  if(val<1) val=1;

//Changed by Wuyou@Sanjie
/*
  if (! who->query_temp("kaifeng_donate_silver")) 
      who->set_temp("kaifeng_donate_silver", 1);
  else if(val>0)
      who->add_temp("kaifeng_donate_silver", val);
*/      
//�����ĲűȽϺ���...

  who->set_temp("kaifeng_donate_silver", val);  
      
  message_vision ("$N������ȡ��"+chinese_number(amount)+
     "��"+obj->name()+"�ŵ��������\n",who);
  
  if(val>0)
    write("�ã����ڹ������������ʱ�佫����"+
          chinese_number(val*3)+"�룡\n");

  obj->set_amount( (int)obj->query_amount()-amount );
  if (obj && obj->query_amount() == 0)
    destruct (obj);

  return 1;
}

