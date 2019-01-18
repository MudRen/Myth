// vendor.c

#include <dbase.h>

inherit NPC_SAVE;

#define PERIOD 72000
// PERIOD is the renting length.
#define MINIMUM 100
// MINIMUM is the minimum amount of bid.

int price_ratio=10;
string owner_id, owner_name;
string owner_long;
string bidder, bidder_name;
string bidder_long;
int bid;
int deposit;
int close_time;
int profit;
int last_profit;

int take_money(int paid, int price);
void set_new_owner(string id, string name, string long);
void set_default_owner(); 
int query_price() {return price_ratio;}
int pay_back(string id, int amount);
void new_owner();
void bad_new_owner();

void set_time(int tim) {close_time=time()+tim;} //for debuging.

int buy_object(object me, string what)
{
	string ob;

	if( stringp(ob = query("vendor_goods/" + what)) )
		return ob->query("value")*price_ratio/10;
	else
		return 0;
}

varargs int complete_trade1(object me, string what, int amount)
{
        string ob_file;
        object ob;
        int price;

        if( stringp(ob_file = query("vendor_goods/" + what)) ) {
            int sale_price=price_ratio;

                ob = new(ob_file);
                if (amount > 1) ob->set_amount(amount);
                if(!ob->move(me)) return 0;
                price=ob->query("value");
                
                if(sale_price>5)
                    sale_price=5;
                ob->set_temp("sale_price", 
                        price*sale_price/10);

                if(!take_money(price*price_ratio/10, price*amount)) {
                    destruct(ob);
                    return 0;
                }
                // save(); save moved to remove().

                message_vision("$N��$n����"+ (amount>1?"һЩ":"һ") + 
                        ob->query("unit") + ob->query("name") + "��\n",
                        me, this_object() );

                return 1;
        }
        return notify_fail("û��������������\n");
}

int complete_trade(object me, string what)
{
	string ob_file;
	object ob;
	int price;

	if( stringp(ob_file = query("vendor_goods/" + what)) ) {
	    int sale_price=price_ratio;

		ob = new(ob_file);
		if(!ob->move(me)) return 0;
		price=ob->query("value");
		
		if(sale_price>5)
		    sale_price=5;
		ob->set_temp("sale_price", 
			price*sale_price/10);

		if(!take_money(price*price_ratio/10, price)) {
		    destruct(ob);
		    return 0;
		}
		// save(); save moved to remove().

		message_vision("$N��$n����һ" + 
			ob->query("unit") + ob->query("name") + "��\n",
			me, this_object() );

		return 1;
	}
	return notify_fail("û��������������\n");
}

// price is the original price.
// paid is what the buyer paid.
int take_money(int paid, int price)
{
    int earn;

		earn=paid-price/2;
		if(earn>=0)
		    profit+=earn;
		else {
		    if(deposit+earn<0) {
			message_vision(
				"\n"+name()+"�Ʋ��ˣ�\n\n",this_object());
                        bad_new_owner(); // by mudring
			return notify_fail("the owner bankrupted\n");
		    }
		    deposit+=earn;
		}
		
		return 1;
}

// this function use moneyd daemon will better
// mudring Sep/08/2002
string price_string(int v)
{
        return MONEY_D->price_str(v);
/*
    string str="";
    int val;
    
    val=v/10000;
    if(val) str+=chinese_number(val) + "���ƽ�";
    val=(v%10000)/100;
    if(val) str+=chinese_number(val) + "������";
    val=(v%100);
    if(val) str+=chinese_number(val)  + "��Ǯ";
    
    if(str=="") str="����Ǯ";

     return str;
*/
}

int do_vendor_list(string arg)
{
	mapping goods;
	string list, *name;
	int i;
	string tlist;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	list = "����Թ���������Щ������\n";
	for(i=0; i<sizeof(name); i++)  {
		tlist = sprintf("%s(%s)", goods[name[i]]->query("name"), name[i]);
		list += sprintf("%-30s��%s\n", tlist,
			price_string(goods[name[i]]->query("value")
				*price_ratio/10 ));
        }
	write(list);
	return 1;	
}

void init()
{
    ::init();
    
    if(close_time<time()+60) new_owner();

    if(!userp(this_player())) return;
    
    add_action("do_bid","bid");
    add_action("do_deposit","deposit");
    add_action("do_setprice", "set_price");
    add_action("do_status","status");
}

int do_bid(string arg)
{
    int minimum, amount;
    string money;
    object who=this_player();
    object who1;
    string roomname;
    object env;
    
    notify_fail("Usage: bid <amount> <gold|silver>\n");

    if(!arg) return 0;
    if(sscanf(arg,"%d %s", amount, money)!=2) return 0;
    
    if(money=="gold") amount*=10000;
    else if(money=="silver") amount*=100;
    else return 0;

    if(amount<1) return 0;
    
    if(!bid) minimum=MINIMUM;
    else {
	minimum=bid;
	if(minimum>MINIMUM*10)
	    minimum+=minimum/10;
	else
	    minimum+=MINIMUM;
    }
    
    minimum=(minimum/100)*100; // round to silver
    if(amount<minimum) return notify_fail(
	    "��������Ҫ��"+price_string(minimum)+"��\n");

    if(who->query("balance")<amount) return notify_fail(
	    "�㻧ͷ��û����ô��Ǯ��\n");
    
    env=environment(this_object());
    if(base_name(env)!=this_object()->query("startroom"))
	roomname=this_object()->query("name");
    else
	roomname=env->query("short");

    if(bidder) {
	pay_back(bidder, bid);
	if(getuid(who)!=bidder) {
	  who1=find_player(bidder);
	  if(who1)
	    tell_object(who1, 
		   who->name()+"����"+price_string(amount)
		  +"�չ�"+roomname+"�����Ͷ��ʧ���ˣ�\n");
	}
    }

    if(close_time<time()+120) close_time+=60; // postpone closing time
                                              // when there are new bidding.
    who->add("balance",-amount);
    who->save();
    
    bidder=who->query("id");
    bidder_name=who->query("name");
    bidder_long=who->long();
    bid=amount;

    save();
    message_vision("$N����"+price_string(amount)+"�չ�"+
	    roomname+"��\n",who);
    
    return 1;
}
    
// optimize for security
// mudring Oct/22/2002
int pay_back(string id, int amount)
{
    object who;
    
    who = UPDATE_D->global_find_player(id);

    if (who)
    {
        who->add("balance",amount);
        log_file("shop_log","pay "+amount+" to "+id+"\n");
        UPDATE_D->global_destruct_player(who, 1);
        return 1;
    }
    else
    {
        log_file("shop_log","Failed to return "+amount+
            " coin to "+id+"\n");
        UPDATE_D->global_destruct_player(who);
        return 0;
    }
}

#if 0
int pay_back(string id, int amount)
{
    object who;
    
    who=find_player(id);
    if(who) {
	who->add("balance",amount);
	if(!who->save()) {
	    log_file("shop_log","Failed to return "+amount+
		    " coin to "+id+"\n");
	    return 0;
	}
	log_file("shop_log","pay "+amount+" to "+id+"\n");
	return 1;
    } else {
	who=new(USER_OB);
	who->set("id",id);
	if(!who->restore()) {
	    log_file("shop_log","Failed to return "+amount+
		    " coin to "+id+"\n");
	    destruct(who);
	    return 0;
	} else {
	    who->add("balance",amount);
	    if(!who->save(1)) { // save(1) will not erase autoload.
		log_file("shop_log","Failed to return "+amount+
			" coin to "+id+"\n");
		destruct(who);
		return 0;
	    } 
	    log_file("shop_log","pay "+amount+" to "+id+"\n");
	    destruct(who);
	    return 1;
	}
    }
}
#endif

int do_deposit(string arg)
{
    object who=this_player();
    string money;
    int amount;
    
    if(getuid(who)!=owner_id) return
	notify_fail("ֻ�е�������������\n");
    
    notify_fail("Usage: deposit <amount> <gold|silver>\n");

    if(!arg) return 0;
    if(sscanf(arg,"%d %s", amount, money)!=2) return 0;
    
    if(money=="gold") amount*=10000;
    else if(money=="silver") amount*=100;
    else return 0;

    if(amount<10000) return notify_fail("һ������Ҫһ�����ӡ�\n");
    
    if(who->query("balance")<amount) return
	    notify_fail("�㻧ͷ��û����ô��Ǯ��\n");

    who->add("balance",-amount);
    who->save();
    
    deposit+=amount;
    save();
    
    write("���ڹ���"+price_string(deposit)+"Ԥ����\n");

    return 1;
}

int do_setprice(string arg)
{
    object who=this_player();
    int ratio, max_price;
    string str;
    
    if(getuid(who)!=owner_id) return
	notify_fail("ֻ�е�������������\n");

    notify_fail("Usage: set_price <ratio> \n"+
                    "<ratio> is between 1 to 20.\n");

    if(!arg) return 0;
    if(sscanf(arg,"%d",ratio)!=1) return 0;
    if(ratio<1) return 0;
    max_price=this_object()->query("max_price");
    if(!max_price) max_price=20;
    if(ratio>max_price) return notify_fail(
	"���۱�������"+chinese_number(max_price)+"��\n");
    
    if(ratio<5 && deposit<1) return
	notify_fail("��Ķ������ڳɱ��������ȸ�����(deposit)��\n");
    
    price_ratio=ratio;
    save();
    
    if(ratio<10)
	message_vision("$N����������Ʒ"+chinese_number(ratio)+
		"�۳��ۡ�\n", who);
    else if(ratio==10)
	message_vision("$N����������Ʒ��ԭ�۳��ۡ�\n", who);
    else {
	str=chinese_number(ratio/10);
	ratio=ratio-(ratio/10)*10;
	if(ratio) str+="��"+chinese_number(ratio);
	message_vision("$N����������Ʒ��ԭ�۵�"+
		str+"�����ۡ�\n", who);
    }
    
    return 1;
}

int do_status(string arg)
{
    object who=this_player();
    int hour, next;
    string str;
    
    if(!close_time) {
	close_time=time()+PERIOD;
	save();
    }
    
    next=close_time-time();
    if(next<60)
	new_owner();
    else {
	hour=next/3600;
	if(hour)
	  str=chinese_number(hour)+"Сʱ";
	else
	    str="";
	hour=(next-hour*3600)/60;
	if(hour)
	    str+=chinese_number(hour)+"����";
        write("Ͷ���ʤ�߽���"+str+"���Ϊ�µ�����\n");
    }

    if(bidder)
      write("��ǰ���Ͷ����"+bidder_name+"("+
	    bidder+")��"+price_string(bid)+"\n");
    else
	write("Ŀǰ��û����Ͷ�ꡣ\n");

    write("����ӯ����"+price_string(last_profit)+"\n");

    if(wizardp(who) || getuid(who)==owner_id) {
	write("\nӯ����������"+price_string(profit)+"\n");
	write("ʣ��Ԥ����"+price_string(deposit)+"\n");
	write("�۸�ָ������"+price_ratio+"\n");
	if(save())
	    write("\nӯ���洢��ϡ�\n"); // when owner check price, save data.
    }
    
    return 1;
}

void new_owner()
{
    int prof;
    object old;
    mapping mail;
    object mbx;
    string msg;

    close_time=time()+PERIOD;
    
    if(owner_id) {
	prof=profit+deposit;
	if(prof>0)
	    pay_back(owner_id, prof);
	old=find_player(owner_id);

	msg="��ĵ���("+name(1)+")���ڽ���������"+
	    price_string(prof)+"�Ѵ�����Ļ�ͷ��\n";
	msg+="����ӯ��"+price_string(profit)+"��"+
	    "ʣ��Ԥ����"+price_string(deposit)+"��\n\n";

	if(old)
	    tell_object(old,msg);
        mail = ([
          "from": name(1) + "(" + query("id") + ")",
          "title": name(1)+"����Ŀ����",
          "to": owner_id,
          "time": time(),
          "status": "N",
          "text": msg
        ]);
	seteuid(getuid());
	mbx=new(MAILBOX_OB);
	mbx->set_owner("vendor_sale");
	mbx->send_mail(owner_id,mail,1);
	destruct(mbx);
    }
    
    if(bidder) {
	owner_id=bidder;
	owner_name=bidder_name;
	owner_long=bidder_long;
	set_new_owner(owner_id, owner_name, owner_long);
    } else  {
	owner_id=0;
	owner_name=0;
	owner_long=0;
	set_default_owner();
    }

    last_profit=profit;
    profit=0;
    deposit=0;
    bidder=0;
    bidder_name=0;
    bid=0;
    price_ratio=10;
    
    save();

}

// for take_money...... by mudring...
void bad_new_owner()
{
    int prof;
    object old;
    mapping mail;
    object mbx;
    string msg;

    close_time=time()+PERIOD;
    
    if(owner_id) {
        prof=profit+deposit;
        if(prof>0)
            pay_back(owner_id, prof);
        old=find_player(owner_id);

        msg="��ĵ���("+name(1)+")���ڽ���������"+
            price_string(prof)+"�Ѵ�����Ļ�ͷ��\n";
        msg+="����ӯ��"+price_string(profit)+"��"+
            "ʣ��Ԥ����"+price_string(deposit)+"��\n\n";

        if(old)
            tell_object(old,msg);
        mail = ([
          "from": name(1) + "(" + query("id") + ")",
          "title": name(1)+"����Ŀ����",
          "to": owner_id,
          "time": time(),
          "status": "N",
          "text": msg
        ]);
        seteuid(getuid());
        mbx=new(MAILBOX_OB);
        mbx->set_owner("vendor_sale");
        mbx->send_mail(owner_id,mail,1);
        destruct(mbx);
    }
    
        owner_id=0;
        owner_name=0;
        owner_long=0;
        set_default_owner();

    last_profit=profit;
    profit=0;
    deposit=0;
    bidder=0;
    bidder_name=0;
    bid=0;
    price_ratio=10;
    
    save();

}

// each NPC file can set two parameters: shop_id and shop_title
// shop_id: how to set player's id once they bought the shop.
// shop_title: how to set player's title.
void set_new_owner(string id, string name, string long)
{
    string short;
    string *newid;

    set_temp("apply/name",({name}));
    
    if(pointerp(newid=query("shop_id"))) {
	newid=({newid[0]+" "+id})+newid;
    } else {
	newid=({"boss "+id, "boss"}); // default setting
    }

    set_temp("apply/id",newid);
    set_temp("apply/long",({long}));

    if(stringp(short=query("shop_title"))) {
	short+=" ";
    } else if(stringp(short=query("title"))) {
	short+=" ";
    } else
        short=query("name")+" ";
    
    short+=name+"("+capitalize(newid[0])+")";
    set_temp("apply/short",({short}));
    message_vision("\n�µ���"+name+"�������Σ�\n\n",
		this_object());
}

void set_default_owner()
{
	delete_temp("apply/name");
	delete_temp("apply/id");
	delete_temp("apply/short");
	delete_temp("apply/long");
}

void reload(string filename)
{
    object me;

    ::reload(filename);
    
    if(owner_id)
	set_new_owner(owner_id, owner_name, owner_long);

    if(close_time<time()+120) close_time+=120; // postpone closing time
                                              // when there are new bidding.

        me=this_object();
        me->set("eff_gin", (int)me->query("max_gin"));
        me->set("gin", (int)me->query("max_gin"));
        me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

        me->set("force", (int)me->query("max_force"));
        me->set("atman", (int)me->query("max_atman"));
        me->set("mana", (int)me->query("max_mana"));


}

string query_save_file()
{
    string id;
    id = query_save_name();
    if( !stringp(id) ) return 0;
    return sprintf(DATA_DIR "npc/boss/%s", id);
}

void die()
{ 
    set("bellicosity",0);

    if(price_ratio>22)
	price_ratio=price_ratio*9/10; // decrease price after death.
    save();
    
    ::die();
}

void remove()
{
       save(); // save profit data before this object is removed.

       ::remove();
}

