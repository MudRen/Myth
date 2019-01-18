//Cracked by Roath
// mon@xyj 8/7/99

inherit NPC_SAVE;

mapping list=([]);
int last_time;
void check_date();

void create()
{
        reload("city_sanhua");
        set_name("����", ({"da shou", "shou"}));
        set("age", 22);
        set("gender", "����");
        set("long",
"�����õ�С��ޣ���Ȼ�书����ô�������ĺ�������Ҳ�����ǡ�\n");
        set("attitude", "heroism");

        set("combat_exp", 10000+random(2000));

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("blade", 20);
	set("str",200);

        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
    int t;

    ::init();
    
    if(userp(this_player())) {
	add_action("do_pay","pay");
	add_action("do_list","list");
	add_action("do_drop","drop");

	
	t=time();
	if(!last_time) {
	    last_time=t;
	    check_date();
	    save();
	} else if(t<last_time) {
	    last_time=t;
	    save();
	} else if((t-last_time)>43200) {
	    last_time=t;
	    check_date();
	    save();
	}
    }
}

void check_date()
{
    int i, t, t1, amount;
    string *key;

    reset_eval_cost();
    i=sizeof(list);
    if(i) key=keys(list);
    else return;
    
    t=time();
    while(i--) {
	t1=list[key[i]]["last_time"];
	if(t<t1) {
	    list[key[i]]["last_time"]=t;
	} else if((t-t1)>604800) {
	    amount=list[key[i]]["amount"];
	    amount=amount*7/10;
	    if(amount<1) {
		map_delete(list, key[i]);
	    } else {
		list[key[i]]["amount"]=amount;
	        list[key[i]]["last_time"]=t;
	    }
	}
    }
    save();
}

int do_pay(string arg)
{
    object me, who;
    int amount, online;
    string id;

    me=this_player();

    if(!arg) return notify_fail("Usage: pay <amount> gold for <id>\n");

    if(sscanf(arg, "%d gold for %s", amount, id)!=2) 
	return notify_fail("��Ҫ���Ͷ��ٻƽ�ȥɱ˭��\n");
    
    if(amount<1) return notify_fail("��Ҫ����һ���ƽ�\n");
    if(amount>1000) return notify_fail("һ�����һǧ���ƽ�\n");
    
    if(me->query("balance")<(amount*10000))
	return notify_fail("����ʻ���û����ô��Ǯ��\n");

    if(wizardp(me))
	return notify_fail("����������²�̫�ðɣ�����\n");

    notify_fail("��Ҫ����ȥɱ˭��\n");
    
    if(!id || sizeof(id)<1) return 0;
    id=replace_string(id,"#"," ");
    id=replace_string(id,"."," ");
    
    who=find_player(id);
    if(!who) { //player not online now.
	seteuid(geteuid(me));
	who=new(USER_OB);
	who->set("id",id);
	if(!who->restore()) {
	    if(who) destruct(who);
	    if(!undefinedp(list[id])) { // suicided already
		map_delete(list, id);
		save();
	    }
	    return notify_fail("�Ҳ��� "+id+" ����ˡ�\n");
	}
	online=0;
    } else {
	online=1;
    }

    if(SECURITY_D->get_wiz_level(who)>0) {
	if(!online) destruct(who);
	return notify_fail("����������²�̫�ðɣ�����\n");
    }

    if(online && amount>=50) {
	tell_object(who,"�����к�Ȼ����һ�������ĸо���\n");
    }

    if(undefinedp(list[id])) {
	if(sizeof(list)>2000) {
	    if(!online) destruct(who);
	    return notify_fail("������׷���������̫���ˡ�\n");
	}

	list[id]=(["amount": amount,
		   "last_time": time(),
		   "name":who->query("name")+"("+
		       capitalize(id)+")",
		   ]);
    } else {
	list[id]=(["amount": amount+list[id]["amount"],
		   "last_time": time(),
		   "name":who->query("name")+"("+
		       capitalize(id)+")",
		   ]);
    }
    
    me->add("balance",-amount*10000);
    me->save();

    save();
    
    message_vision("$N��"+chinese_number(amount)+
	    "���ƽ�����"+who->query("name")+
	    "("+id+")ͷ­��Ŀǰ���ͽ�"+
	    chinese_number(list[id]["amount"])+
	    "����\n", me);
    
    log_file("sanhua","["+ctime(time())+"] "+
	    me->query("id")+" paid "+amount+" gold for "+
	    id+".\n");
    if(!online) destruct(who);

    return 1;
}

string get_time(int last)
{
    int day;
    string result;

    if(!last) last=time();
    last=time()-last;
    if(last<0) last=0;
    
    last/=3600;
    day=last/24;
    last=last%24;
    if(day) result=chinese_number(day)+"��";
    else result="";
    
    result+=chinese_number(last)+"Сʱ";
    return result;
}
int do_list(string arg)
{

    int i;
    string format, result, *key;
    string *sort=({});

    i=sizeof(list);
    if(i<1) return notify_fail(
	    "Ŀǰû���˱�׷ɱ��\n");

    format="��%-24s%20s%20s\n";

    result="\n"+sprintf(format,"����������","�͡���",
	    "���ϴ������ͽ�")+
 "������������������������������������������������������������������������\n";


    if(!arg) {
        key=keys(list);
	while(i--) {
	    sort+=({sprintf("%6d",list[key[i]]["amount"])
		    +"|"+
		    sprintf(format,list[key[i]]["name"],
		    chinese_number(list[key[i]]["amount"])+"��",
		    get_time(list[key[i]]["last_time"]))});
	}
	if(i=sizeof(sort)) {
	    sort=sort_array(sort,1);
	    while(i--) {
		result+=sort[i][strsrch(sort[i],"|")+1..];
	    }
	}
    } else {
	if(undefinedp(list[arg])) return
	    notify_fail("û��������׷ɱ "+arg+"��\n");

	result+=sprintf(format,list[arg]["name"],
		chinese_number(list[arg]["amount"])+"��",
		get_time(list[arg]["last_time"]));
    }
    result+=
 "������������������������������������������������������������������������\n";

    this_player()->start_more(result);
    return 1;
}

int do_drop(string arg)
{
    object me, ob;
    string id;

    me=this_player();

    if(!arg) return 0;

    if(!(ob=present(arg,me))) return 0;

    if(!ob->is_corpse()) return 0;
    
    if(!ob->query("is_player")) return 0;
    
    id=ob->query("victim_id");
    if(!id) return 0;
    
    if(undefinedp(list[id]))  return 0;
    
    message_vision("$N�����ϱ��ŵ�ʬ��������һˤ��"+
	    "$n��æ��ǰϸ����������¶ϲɫ��\n",me,this_object());
    message_vision("$N��$nС���ֹ�������������ģ���Ȼ��"+
	    list[id]["name"]+"��Ū���ˣ���"+
	    chinese_number(list[id]["amount"])+
	    "������С�ľͰ�����Ǯׯ����\n\n",this_object(),me);

    me->add("balance",10000*list[id]["amount"]);
    log_file("sanhua","["+ctime(time())+"] "+me->query("id")
	    +" is paid "+list[id]["amount"]+" gold for "
	    +list[id]["name"]+"'s corpse.\n");

    map_delete(list, id);
    save();
    destruct(ob);
    
    return 1;
}
