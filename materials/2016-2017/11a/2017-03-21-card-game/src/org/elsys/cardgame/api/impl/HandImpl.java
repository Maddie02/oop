package org.elsys.cardgame.api.impl;

import java.util.List;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Hand;

public class HandImpl implements Hand {

	private List<Card> cards;
	
	public HandImpl(List<Card> handCards) {
		this.cards = handCards;
	}

}
