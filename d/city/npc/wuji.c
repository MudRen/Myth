
inherit NPC;

void create()
{
       set_name("�����޼�", ({"zhangsun wuji","wuji"}));
       set("gender", "����");
	set("title","��������");
       set("age", 55);
       set("str", 25);
	set("int",30);
       set("attitude", "friendly");
        set("combat_exp", 30000);
	set("daoxing", 50000);

        set("attitude", "friendly");
        set("class", "scholar");
        set_skill("unarmed", 50);
        set_skill("dodge",50);
        set_skill("literate", 100);
        set_skill("parry", 50);

        set("force", 500);

       setup();

       carry_object("/d/obj/cloth/choupao")->wear();
       add_money("silver", 1);
}

void init()
{
        object ob;
       
        ::init();
        add_action("do_apply", "apply");
          add_action("do_newname", "newname");
}

int do_apply(string args)
{
   string respect_type,respect_str;
   object me=this_player();
   object mymoney;
   int dx,amount;
   
   if (!args || sscanf(args,"%s to %s",respect_type,respect_str) !=2)
   {
      tell_object(me,"��ʽΪ: apply <Ҫ���������> to <�ƺ�> \n"+
		     "��������ĳƺ�����: \n"+
                     "  respect       ���˶��Լ������(����500��,�ƽ�50��)\n"+
//		     "  rude          ���˶��Լ��Ĵ�³�ĳƺ�(����500��,�ƽ�50��)\n"+
                     "  self          �Լ����Լ��ĳƺ�(����100��,�ƽ�50��)\n"+
                     "  self_rude     �Լ����Լ���³�ĳƺ�(����100��,�ƽ�50��)\n"+
                     "�֣�����ʹ�ò�ǡ���ĳ�ν����Ȼ�ƺ���ȡ������ʮ��\n"+
                     "���ӾͰװ����ˡ�����ǡ����������������ɾ�����\n");

      return 1;
   }
   else 
   {
        mymoney=present("gold_money",me);
	if (!mymoney)
         {
	    command("heng");
            return notify_fail("�����޼�˵��:��ûǮ������ʲô����?\n");
         }
	switch (respect_type)
 	{
          case "respect":
//        case "rude":
            {
		dx=500000;
		amount=50;
		break;
	    }
	  case "self" :
	  case "self_rude":
	    {
		dx=100000;
		amount=50;
		break;
	    }
	  default:
	     return notify_fail("��Ҫ�������ֳƺ�?\n");
	}
	if (me->query("daoxing") < dx)
           return notify_fail("��ĵ��в���. \n");
	if (mymoney->query_amount() < amount)
           return notify_fail("��Ľ��Ӳ���. \n");
           me->set("rank_info/"+respect_type,respect_str);
	     if (mymoney->query_amount() == amount)
               destruct(mymoney);
             else
               mymoney->add_amount(-amount);
          }
	message_vision("�����޼ɵ��˵�ͷ, �������һ�������ϸ��˼���.\n",me);
	return 1;

}
  int do_newname(string args)
  {
     string urname;
     object me=this_player();
     object mymoney;
     int dx,amount,age;
     if (!args)
     {
        tell_object(me,"��ʽΪ: newname <���������> \n"+
                       "ע�⣺��ƽ�200��\n");
        return 1;
     }
     else 
     {
          mymoney=present("gold_money",me);
          if (!mymoney)
           {
              command("heng");
              return notify_fail("�����޼�˵��:��ûǮ�ҿɲ��ܸ��������Ŷ.\n");
           }
                  amount=200;
          if (mymoney->query_amount() < amount)
             return notify_fail("��Ľ��Ӳ��������ֵ�. \n");
             me->set("name",args);
               if (mymoney->query_amount() == amount)
                 destruct(mymoney);
               else
                 mymoney->add_amount(-amount);
            }
          message_vision("�����޼ɵ��˵�ͷ, �������һ�������ϸ��˼���.\n",me);
          return 1;
  }
