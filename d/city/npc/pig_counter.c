inherit F_VENDOR_SALE;

#define MAXSIZE 200
#define TOP 10
#define LIMIT 86400*2

string *pig_id=({});
string *pig_name=({});
int *pig_rank=({});
string *who_played=({}); // who in top ten have played recently.
                         // if in top ten and no play for a while,
                         // will reduce rank points.
int next_time=0; // when is the next time to check whether played.

void greeting(object ob);
void mark_played(int i, string id);
int ask_pig();

string *query_id() {return pig_id;}
string *query_name() {return pig_name;}
int *query_rank() {return pig_rank;}
void set_next(int next) {next_time=time()+next;return;}
int query_next() {return next_time-time();}
string *query_played() {return who_played;}
int query_id_rank(string id);

void create()
{
        reload("city_pig_counter");
	set_name("������", ({"pig king","king","pig"}));
	set("shop_id",({"king","pig"}));
        set("gender", "����");
	set("vendor_goods", ([
		"cake": "/d/obj/food/cake",
		"pig": "/d/obj/food/pig",
		"cha gan": "/d/obj/food/chagan",
		"putao": "/d/obj/food/grape",
		"putao gan": "/d/obj/food/putaogan",
		"huasheng": "/d/obj/food/wuxianghuasheng",
		"jiudai": "/d/obj/food/huadiao-jiudai",
//		"pighead": "/d/obj/food/pighead",
		// pig head only available through gong zhu. :)
		]));
	set("inquiry", ([
		"pig": (:ask_pig:),
		"rank": (:ask_pig:),
		"����": (:ask_pig:),
		"�ȼ���": (:ask_pig:),
		]));
        setup();
	
	if(!next_time) {
	    next_time=time()+LIMIT; // check 24 hours later.
	    save();
	}
	if(!who_played) who_played=({});
}

void update_rank(string id, string name, int rank)
{
    int i, j, k;
    
    if((i=member_array(id,pig_id))>-1) {
	mark_played(i,id);
	if(rank!=pig_rank[i]) {
	    pig_id=pig_id[0..(i-1)]+pig_id[(i+1)..];
	    pig_rank=pig_rank[0..(i-1)]+pig_rank[(i+1)..];
	    pig_name=pig_name[0..(i-1)]+pig_name[(i+1)..];
	} else return; // no change
    }
    
    i=sizeof(pig_rank);
    while(i--) {
	if(rank<=pig_rank[i]) break;
    }
    
    if(i>=(MAXSIZE-1)) return; // less than the last one, no change.

    i++; // this is the new position for who.
    pig_id=pig_id[0..(i-1)]+({id})+pig_id[i..(MAXSIZE-1)];
    pig_rank=pig_rank[0..(i-1)]+({rank})+pig_rank[i..(MAXSIZE-1)];
    pig_name=pig_name[0..(i-1)]+({name})+pig_name[i..(MAXSIZE-1)];

    mark_played(i,id);

    save();
    environment(this_object())->reset_long();
}

void mark_played(int i, string id)
{
    if(i>=TOP) return;
    // don't mark those who are not in TOP
    
    if(member_array(id, who_played)>-1) return; // already marked.
    
    who_played+=({id});
    save();
}

string pig_bang()
{
    string msg;
    int i, j;
    
    msg= "�������������������������������а�\n";
    msg+="��������������������������������������������������\n";
    
    j=sizeof(pig_id);
    if(j>TOP) j=TOP;
    if(j>0)
      for(i=0;i<j;i++) {
	    msg+=sprintf("������������%-24s��%6d��\n",
		    pig_name[i]+"("+capitalize(pig_id[i])+")",
		    pig_rank[i]);
    }
    
    msg+="��������������������������������������������������\n\n";
    
    return msg;
}

void init()
{
    int rank, rank1, i;
    string id;
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
    add_action("do_vendor_list", "list");
    
    if(!ob || !userp(ob)) return;
    
    rank=(int)ob->query("piggy/rank");
    if(rank<1) return;

    id=ob->query("id");
    if((i=member_array(id, pig_id))==-1) return;
    rank1=pig_rank[i];
    if(rank<rank1) {
	// will update when players play.
//	update_rank(id, ob->query("name"), rank);
//	log_file("pig_log",ctime(time())+id+" lost "+(rank1-rank)+
//		" points on the board.\n");
//    } else if(rank>rank1 && rank1>=100) {
// won't lose point for no-show    xlb 2.4.99
    } else if(rank>rank1 && rank1>=100 && rank1<100) {
	message_vision("$N��$n��������˵����"+
		"��Ϊ�����û�������ȼ��ּ�����"+
		chinese_number(rank-rank1)+"�㣺��\n",
		this_object(), ob);
	log_file("pig_log",ctime(time())+id+" lost "+(rank-rank1)+" points.\n");
	ob->set("piggy/rank",rank1);
	ob->save();
    }
}

int query_id_rank(string id)
{
    int i;

    if((i=member_array(id, pig_id))==-1) return -1; // not in list.
    return pig_rank[i];
}

void check_time()
{
    int tt, i, j, rank;
    string id;
    
    if(!next_time) {
	next_time=time()+LIMIT;
	save();
	return;
    }
    
    tt=time()-next_time;
    if(tt<-LIMIT+10 || tt>LIMIT+10) { // must be sth wrong with system clock.
	                        // so reset timing.
	next_time=time()+LIMIT;
	save();
	return;
    }
	
    if(tt<0) return; // time not up yet.
    
    next_time=time()+LIMIT;
    
    // now check whether top ten played or not.
    j=sizeof(pig_id);
    if(j>TOP) j=TOP;
    if(j>0) {
	for(i=j-1;i>=0;i--) {
	    id=pig_id[i];
	    if(member_array(id, who_played)==-1) { // didn't play
		rank=pig_rank[i]-1;
		if(rank<100) continue; // won't drop below 100
		update_rank(id, pig_name[i], rank);
	    }
	}
    }
    who_played=({});
    save();
}

void greeting(object ob)
{
    check_time();

    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
    if(random(3)==0)
	message_vision("$N��$nߺ�ȵ����Ϻõ���ͷ�⣡�չ��ã�\n",
	    this_object(), ob);
}

int do_bid(string str)
{
    int i;
    object who=this_player();
    string id=who->query("id");
    
    if((i=member_array(id,pig_id))>-1) 
	if(i<TOP)
	    return ::do_bid(str);
    
    message_vision("$N��$n˵���뵱"+query("name")+
	    "�㻹Ҫ�������϶�������\n",this_object(), who);
    return 1;
}


int ask_pig()
{
    object who=this_player();
    int i, j;
    
    i=(int)who->query("piggy/rank");
    
    if(i<1) {
	message_vision("$N��$n˵���㻹û�вμ�������\n",this_object(), who);
	return 1;
    }

    if((j=member_array(who->query("id"),pig_id))>-1) {
	// see whether a tie?
	int tie=0;
	while(j--) {
	    if (pig_rank[j]!=pig_rank[j+1]) {break;}
	    tie=1;
	}
	
	j++; // to compensate for the j--

	message_vision("$N��ϸ���˿������˵��$n���еȼ���"+
		chinese_number(i)+"�㣬λ�����а�"+
		(tie?"����":"")+"��"+
		 chinese_number(j+1)+"����\n",this_object(), who);
	return 1;
    } else if(sizeof(pig_id)<MAXSIZE) {
	message_vision("$N��ϸ���˿������˵��$n���еȼ���"+
		chinese_number(i)+"�㣬����Ҫ�μӹ�����ܽ������а�\n",
		this_object(), who);
	return 1;
    } else {
	message_vision("$N��ϸ���˿������˵��$n���еȼ���"+
		chinese_number(i)+"�㣬��û�н���ǰ"+
		chinese_number(MAXSIZE)+"����\n",
		this_object(), who);
	return 1;
    }
}
