//Cracked by Roath
// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string id,file,club_name;
	object mark,ob,old_mark;
	mapping ob_info;
	int level;
	seteuid(getuid());
        if (! SECURITY_D->valid_grant(me, "(arch)")) return 0;
        if(!arg) return notify_fail("ָ���ʽ : setclub <ĳ��> with (������ﵵ��·��)\n");
        else
        {
        	if( sscanf(arg, "%s with %s", id, file)!=2 ) return notify_fail("ָ���ʽ : setclub <ĳ��> with (������ﵵ��·��)\n");
                ob = present(id, environment(me));
                if (!ob) ob = find_player(id);
                if (!ob) ob = find_living(id);
	        if (!ob) return notify_fail("û��������.\n");
		
		if(!mark=new(file)) return notify_fail("û�����������ǵ�������ȷ.\n");
		if(!stringp(club_name=mark->query("club"))) return notify_fail("��������<club>���ϲ���ȷ.\n");
		 if( (mark->query_weight()+ob->query_encumbrance())>ob->query_max_encumbrance() )
 		 return notify_fail(ob->name(1)+"�ò���"+mark->query("name")+"��\n");
		ob->delete("club");

		CLUB_D->add_club(mark->query("club_id"));
		
		if(mark->query("club_max_level") > 1) level=mark->query("club_max_level");
			else level=5;
		
		ob_info=([
				"level": level,
				"title": "��ᴴʼ��",
				"info1": "��",
				"info2": ctime(time()),
				"info3": me->name_id(1),
		]);
		
		CLUB_D->set_member(mark->query("club_id"),getuid(ob),ob_info);
		CLUB_D->set_club_leader(mark->query("club_id"),getuid(ob));
		while(old_mark=present("club_mark", ob)) destruct(old_mark);
		mark->move(ob);
		message_vision("$N��$n����Ϊ"+club_name+"�Ĵ�ʼ�ˡ�\n",me,ob);
		ob->save();
	}
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : setclub <ĳ��> with (������ﵵ��·��)

��һ���������Ϊ�����ϴ�
HELP
    );
    return 1;
}
