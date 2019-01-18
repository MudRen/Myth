//Cracked by Roath
// hockshop.c
// modified by mon 2/28/98

inherit ROOM;

string *sell_msg = ({
		"�������ã�һ�Ĳ�ֵ",
		"�ʵص��ӣ��ѿ�֮��",
		"�������ƣ�����Ѭ��",
});

object shop_box;

int query_max_items() {return 50;}
string get_name(string str);

void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
	add_action("do_retrieve", "retrieve");
	add_action("do_buy", "buy");
	add_action("do_list", "list");
//  add_action("do_quit", "quit");

	set("no_clean_up", 1);
}

// find the shopbox object for this shop to hold sold items.
object findbox()
{
    if(shop_box && environment(shop_box)==this_object()) 
      return shop_box;

    shop_box=new(__DIR__"shopbox");
    shop_box->move(this_object());
    return shop_box;
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "������"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}

void pay_player(object who, int amount)
{
	object ob;

	if( amount < 1 ) amount = 1;
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		if(!ob->move(who))
		  ob->move(environment(who));
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		if(!ob->move(who))
		  ob->move(environment(who));
	}
}

int do_value(string arg)
{
	object ob;
	int value, sale, amount;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲô��Ʒ�����̹��ۣ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	value = ob->query("value");

	if((amount=ob->query_amount())>0) {
	    if(value>ob->query("base_value")*amount)
		return notify_fail("��"+ob->query("unit")+
			ob->name()+"�������㣬���²�ֵǮ��\n");
	} 

	sale=ob->query_temp("sale_price");
	if(sale>0 && sale<value) value=sale;

	if( !value) printf("%sһ�Ĳ�ֵ��\n", ob->query("name"));
	else 
		printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�һ�ŵ�Ʊ��\n�������(sell)�������õ�%s��\n",
			ob->query("name"), value_string(value),
			value_string(value * 80 / 100));

	return 1;
}

int do_pawn(string arg)
{
	object ob, stamp_ob;
	int value, sale;
	string obj_file;
	int  i, amount;
	mixed no_sell;
	object *inv;
	int oldnum;
	string id;

	if( this_player()->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ�䵱ʲô��Ʒ��\n");

	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");

	if( ob->query("material") == "ice" )
		return notify_fail("�ƹ��˵�����Ķ�����������û����š�\n");
	//cuz ice melts, will cause problem, so disabled...weiqi, 970930.

	value = ob->query("value");

	if((amount=ob->query_amount())>0) {
	    if(value>ob->query("base_value")*amount)
		return notify_fail("��"+ob->query("unit")+
			ob->name()+"�������㣬���²�ֵǮ��\n");
	} 

	sale=ob->query_temp("sale_price");
	if(sale>0 && sale<value) value=sale;

	if( !value || value < 10) return notify_fail("����������ֵǮ��\n");
	
	// by Snowcat Sep 8 1998 
	no_sell = ob->query("no_sell");
        if(no_sell) {
	   if (stringp(no_sell))
	       return notify_fail((string)no_sell);
	   return notify_fail("������������������\n");
	}

/*
no need to check number now since now pawn pays no money.
pawn pays no money to prevent people using pawn to sell too much 
stuffs (easy to have bug so that player can get unlimited supply
of certain items). checking number here is not useful because
people can destroy the pawn stamp to get rid of the pawned items,
then can pawn again.
pawn is not a method to get temporary money (as in real life)
any way in this game. people seldom need to retrieve the items
they pawn.
	// mon 9/29/98
	inv=all_inventory(findbox());
	id=ob->query("id");
	i=sizeof(inv);
	oldnum=0;
	while(i--) {
	    if(inv[i]->query("id")==id)
		oldnum++;
	}
	if(oldnum>=10)
	    return notify_fail("�ƹ��˵�������������ڴ��"+
		       "̫�࣬��ʱ���չ��ˡ�\n");
*/

        stamp_ob = new("/obj/stamps");

	stamp_ob->set_temp("file", ob);
	stamp_ob->set_temp("value", value*10/100);
	stamp_ob->set_temp("player", this_player()->query("id"));
	stamp_ob->set_temp("long_1", this_player()->name()+"�䵱" +
	   ob->query("name") + "һ" + ob->query("unit") +
	   "��������ȱ�𲻿���");
        stamp_ob->set_temp("long_2", "���Ӧ��"+
		value_string(value*10/100)+"����һ�ֽ�Ǯ��һ�ֽ�����");

	write("�ƹ�ĳ�����Ѻ"+ sell_msg[random(sizeof(sell_msg))] +
	  ob->query("name") + "һ" + ob->query("unit") + "��\n",
	  this_player());
	message_vision("$N�����ϵ�" + ob->query("name") + 
		"�ó�������һ�ŵ�Ʊ��\n",this_player());

	this_player()->start_busy(1);
	stamp_ob->move(this_player());

	//destruct(ob);
	ob->move(findbox());

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value, sale;
	string obj_file;
	int i, oldnum, amount;
	string index;
	mixed no_sell;
	int dest;
	int destroy_after_sell;// 11/15/98 mon
	                       // this is for items such as poisoned containers.
	                       // after sell, will not increase dangpu's 
	                       // inventory, so can't sell then buy back.

	if( this_player()->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲô��Ʒ��\n");

	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");

	value = ob->query("value");

	if((amount=ob->query_amount())>0) {
	    if(value>ob->query("base_value")*amount)
		return notify_fail("��"+ob->query("unit")+
			ob->name()+"�������㣬���²�ֵǮ��\n");
	} 

	sale=ob->query_temp("sale_price");
	if(sale>0 && sale<value) value=sale;
	if( !value ) return notify_fail("����������ֵǮ��\n");

	// by Snowcat Sep 8 1998 
	no_sell = ob->query("no_sell");
        if(no_sell) {
	   if (stringp(no_sell))
	       return notify_fail((string)no_sell);
	   return notify_fail("������������������\n");
	}

	if( ob->query("material") == "ice" )
		return notify_fail("�ƹ��˵�����Ķ�����������û����š�\n");
	//cuz ice melts, will cause problem, so disabled...weiqi, 970930.

        index=ob->query("name")+"("+ob->query("id")+")";

	// 11/15/98 mon
	destroy_after_sell=ob->query_temp("destroy_after_sell");

	if(destroy_after_sell) {
	    // not to change the inventory.
	    ob->move(findbox());
	    dest=1;
	} else {
	 if(!findbox()->query_temp("goods/"+index) ){
           findbox()->set_temp("goods/"+index, ob);
	   findbox()->set_temp("numbers/"+index, 1);
	   ob->move(findbox());
	   dest=0;
	 }
	 else {
	   oldnum = findbox()->query_temp("numbers/"+index);
	   if(oldnum>=100)
	       return notify_fail("�ƹ��˵�������������ڴ��"+
		       "̫�࣬��ʱ���չ��ˡ�\n");
           findbox()->set_temp("numbers/"+index, oldnum+1);
	   dest=1;
	 }
	}

	write("�ƹ�ĳ�����"+ sell_msg[random(sizeof(sell_msg))] +
	  ob->query("name") + "һ" + ob->query("unit") + "����"+
	   value_string(value*80/100)+ "��\n");
	message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
		this_player());

	if(dest)
	   destruct(ob);

	this_player()->start_busy(1);
	pay_player(this_player(), value * 80 / 100);

	return 1;
}

int do_retrieve(string arg)
{
	object ob;
	int value, afford;
	object pawn_ob;

	if( this_player()->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ���ʲô��Ʒ��\n");

	if( ob->query("id") != "pawn stamp")
	   return notify_fail("��Ҫ�õ�Ʊ���������Ʒ��\n");

	value = ob->query_temp("value");
	if(!value) 
	   return notify_fail("�ÿհ׵�Ʊ��������컯��֮�����ٲ��ɣ�\n");

	if( !(afford = this_player()->can_afford(value)) )  {
	   return notify_fail("��û���㹻��Ǯ����ء�\n");
	}
	else if( afford == 2 )
       return notify_fail("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");

	if( ob->query_temp("player") != this_player()->query("id"))
	   return notify_fail("�ֲ����㵱�ģ���û��ٰ���\n");

	pawn_ob = ob->query_temp("file");
	if(!pawn_ob) {
	  destruct(ob);
	  return notify_fail
	    ("�ƹ�ľ�������⣡��Ҫ�Ķ����Ҳ����ˡ�\n");
        }

	if(!pawn_ob->move(this_player())) return 0;
	destruct(ob);

	write("�ƹ�ĳ�����"+ sell_msg[random(sizeof(sell_msg))] +
	  pawn_ob->query("name") + "һ" + pawn_ob->query("unit") + "������"+
	   value_string(value)+ "��\n");
	message_vision("$N�õ�Ʊ���һ"+pawn_ob->query("unit")+
	   pawn_ob->query("name")+"��\n", this_player());

        this_player()->start_busy(1);
	this_player()->pay_money(value);
	this_player()->save();

    return 1;
}


int do_list(string arg)
{
   mapping goods;
   string list, *name;
   int i;
   int j=0;
   string tlist;
   object me=this_player();

   if( !mapp(goods = findbox()->query_temp("goods")) )
	  return notify_fail("����Ŀǰû���κλ��������\n");
   name = keys(goods);
   if(!sizeof(goods)) 
	  return notify_fail("����Ŀǰû���κλ��������\n");

   if( !arg )   {
      list = "����Թ���������Щ������\n";
      i=sizeof(goods);
      while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
	     //mon 2/4/98 because some items may destruct themselves
	     //after being sold.

	     tlist = get_name(name[i]);
	     list += sprintf("%3d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	       value_string(goods[name[i]]->query("value")),
	       chinese_number(findbox()->query_temp("numbers/"+name[i])),
	       goods[name[i]]->query("unit") );
      }
      me->start_more(list);
   } else if( arg == "book" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }

	        if( mapp(goods[name[i]]->query("skill")) )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("����Ŀǰû�����ֻ�Ʒ��\n");
      else {
	list = "����Թ���������Щ������\n"+list;
	me->start_more(list);
      }
   } else if( arg == "drug" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
		 if( goods[name[i]]->query("drug_type") )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("����Ŀǰû�����ֻ�Ʒ��\n");
      else {
	list = "����Թ���������Щ������\n"+list;
	me->start_more(list);
      }
   } else if( arg == "axe" || arg == "blade" || arg == "dagger" || 
	arg == "fork" || arg == "hammer" || arg == "spear" || arg == "mace" || arg == "rake" ||
	arg == "staff" || arg == "stick" || arg == "sword" || arg == "whip" ||
	arg == "throwing" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }

		 if( goods[name[i]]->query("skill_type") == arg )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("����Ŀǰû�����ֻ�Ʒ��\n");
      else {
	list = "����Թ���������Щ������\n"+list;
	me->start_more(list);
      }
   } else if( arg == "archery" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
		 if( goods[name[i]]->query("apply/skill_type") == arg )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("����Ŀǰû�����ֻ�Ʒ��\n");
      else {
	list = "����Թ���������Щ������\n"+list;
	me->start_more(list);
      }
   } else if( arg == "armor" || arg == "boots" || arg == "cloth" ||
	 arg == "finger" || arg == "hands" || arg == "head" || arg == "neck" ||
	 arg == "shield" || arg == "surcoat" || arg == "waist" ||
	 arg == "wrists" )   {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
		 if( goods[name[i]]->query("armor_type") == arg )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("����Ŀǰû�����ֻ�Ʒ��\n");
      else {
	list = "����Թ���������Щ������\n"+list;
	me->start_more(list);
      }
   } else   {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
	     
	     // mon 12/24/99
	     // allow list/buy using item Chinese name which will make
	     // it easier to select the desired one.
		 if( member_array(arg, 
			     goods[name[i]]->parse_command_id_list()) != -1 ||
			 strsrch(name[i], arg)>=0 )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s��%-20s����ʣ%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("����Ŀǰû�����ֻ�Ʒ��\n");
      else {
	list = "����Թ���������Щ������\n"+list;
	me->start_more(list);
      }
   }

   return 1;
}


int do_buy(string arg)
{
   mapping goods;
   string *name;
   string fname;
   object obj_file, ob;
   int value, oldnum, afford, order;
   int i, j;
   object* inv;
   string arg1, arg2;

	if( this_player()->is_busy() )
		return notify_fail("��������æ���ء�\n");

   if( !arg )  {
	   write("ָ���ʽ��buy <ĳ��>\n");
	   return 1;
   }

   // players are used to the "buy sth from sb" format.
   if( sscanf(arg, "%s from %s", arg1, arg2) == 2 )   {
	  arg = arg1;
   }

   if( sscanf(arg, "%s %d", fname, order) != 2 )   {
	  fname = arg;
	  order = 1;
   }

   if( !mapp(goods = findbox()->query_temp("goods")) )
	  return notify_fail("����Ŀǰû���κλ��������\n");
   name = keys(goods);
   if(!sizeof(goods)) 
	  return notify_fail("����Ŀǰû���κλ��������\n");

   j = 0;
   i=sizeof(name);
   while(i--) {
          if(!goods[name[i]]) continue;

	  // mon 12/24/99
	  // allow list/buy using item Chinese name which will make
	  // it easier to select the desired one.

	  if( member_array(fname, 
	          goods[name[i]]->parse_command_id_list()) != -1 ||
	      strsrch(name[i], fname)>=0 )  {
	     j++;	 
	  }
	  if( j == order )   {
		  obj_file = goods[name[i]];
          value = obj_file->query("value"); 
          if( !(afford=this_player()->can_afford(value)) )  {
	          write("��û���㹻��Ǯ��\n");
	          return 1; 
          }
          else if( afford == 2 )  {
              write("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");
	          return 1;
   		  }

		  ob = new( base_name( obj_file ) ); 
		  ob->set_name(obj_file->query("name"),
		    obj_file->parse_command_id_list());
		    //so that the bought item would be the
		    //same as the one on sale.

   		  if(!ob->move(this_player()))
		    return 0;

   		  this_player()->start_busy(1);

		  arg = obj_file->query("name")+
		    "("+obj_file->query("id")+")";
   		  oldnum = findbox()->query_temp("numbers/"+arg);
   		  if(oldnum == 1)  {
		         destruct(obj_file);
	  		 findbox()->delete_temp("numbers/"+arg);
	  		 findbox()->delete_temp("goods/"+arg);
   		  }
   		  else    {
	  		 findbox()->set_temp("numbers/"+arg, oldnum-1); 
		  }

   		  this_player()->pay_money(value);
		
   		  message_vision("$N��������һ" +
			ob->query("unit") + ob->query("name") + "��\n", this_player() );

		  this_player()->save();
		  return 1;
	  }
   }

   write("������û�����ֻ�Ʒ��\n");

   return 1;
}

int do_quit()
{
        object me=this_player();
        if ( me->query_temp("no_move") )
	    return notify_fail("�㱻��ס�ˣ������˵ó���Ϸ��\n");
	if(!me->query_temp("suicide_countdown")) {
	    if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ������˳���)\n");
	} //to allow halt suicide :D by mon 9/9/97

	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);

	this_player()->move("/cmds/std/quitroom");
	return 1;
}

// no clean up at hockshop to prevent items lose.
int clean_up()  
{
      return 0;
}

// strip away ansi color code.
// mon 5/7/98
string get_name(string str)
{
    string str1, str2;

    while(sscanf(str,"%s%*sm%s",str1,str2)==3)
	str=str1+str2;
    return str;
}
