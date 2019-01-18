// mon@xyj 10/10/98

inherit ROOM;

void dest();

void create()
{
  set ("short", "������");
  set ("long", @LONG

�����ص��������廷�����ǳ����ߣ���¹��Ⱥ�С�ǧ�ߴ���������
���ߡ���������������¹ַ硣���Ծ���ǳ�����������������
޵����Ŀ���������졣

ɽ·��һ�����������湩����ǰ����ɮ������������Ҳ���ϰ�Ѱ��
���������ϵ���������(bury)��

LONG);

  set("exits", ([
	  "westdown":"/d/qujing/baoxiang/yelu"+
          (random(3)+1),
	  ]));

  setup();
}

void init ()
{
    object me=this_player();

    if(me->query_temp("startroom")) {
	me->set("startroom",me->query_temp("startroom"));
    } else {
	me->delete("startroom"); // use default start room.
    }
    me->save();
    call_out("dest",2);
    add_action("do_bury","bury");
}

void go_back(object dest, object me)
{
    object env;
    if(!me) return;
    if(present("sheli zi",me)) return;

    env=environment(me);
    if(!env || env!=this_object()) return;
    message_vision("ƽ��һ����磬��$N������������������ˡ�\n",me);
    me->move(dest,1);
    message_vision("�羡����$N���˳�����\n",me);
    return;
}
    
int do_bury(string arg)
{
    object me=this_player();
    object dest=me->query_temp("old_place");
    int i;
    object obj;

    if(dest)
	call_out("go_back",2,dest,me);

    if(!arg) return notify_fail("��Ҫ��ʲô��\n");
    if(!obj=present(arg,me))
	return notify_fail("������û������������\n");
    if(obj->query("id")!="sheli zi")
	return notify_fail("�������������������\n");
    i=obj->query_amount();
    message_vision("$N�������������������˸��ӣ���"+
	    chinese_number(i)+obj->query("base_unit")+
	    obj->query("name")+"�Ž�ȥ����С���������������\n",me);
    me->add("potential",4*i);
    tell_object(me,"���գ����գ����Ǳ��������"
	    +chinese_number(4*i)+"�㣡\n");
    destruct(obj);
    log_file("shelizi",ctime(time())+" "+me->query("id")+
	    " got "+4*i+" pot\n");
    return 1;
}

void dest()
{
    object* child=children(__DIR__"small_cave");
    int i=sizeof(child),j;
    object *obj;
    
    while(i--) 
	if(clonep(child[i])) {
	    obj=all_inventory(child[i]);
	    j=sizeof(obj);
	    while(j--) {
		if(userp(obj[j])) {
		    tell_object(obj[j],
			    "��ֻ������ط·������������㱻�͵�˦�˳�ȥ������\n");
		    obj[j]->move(this_object(),1);
		    message_vision("$Nһ����ͷ���Ӳ��з��˹�������������ã��\n",
			    obj[j]);
		} 
	    }
	    destruct(child[i]);
	}
}

